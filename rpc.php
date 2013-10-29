<?php

ignore_user_abort(true);
set_time_limit(0);

include_module ('siteclone');
$clone = new siteclone();

// check for correct id. 
$row = $clone->getRowFromMD5($_GET['id']);
if (empty($row)) {
    echo lang::translate('siteclone_no_such_id');
    die;
}

// already verified
if ($row['verified'] == 1) {
    echo lang::translate('siteclone_already_validated');
    die;
}

// create config dir
$servername = $row['sitename'] . '.' . config::getMainIni('server_name') ;
$config_dir = _COS_PATH . "/config/multi/$servername";

if (!file_exists($config_dir)) {    
    $res = @mkdir($config_dir);
    if (!$res) { 
        //$message = "Administer has ¤#¤%& up. Can not make config dir.\nAsk him to set correct permissions\ne.g. ./coscli.sh file --chmod-files\n";
        $message = lang::translate('siteclone_rpc_can_not_make_dir');
        die(nl2br($message));
    } else {
        //$message = "Created config dir\n";
        $message = lang::translate('siteclone_rpc_created_config_dir');
        echo nl2br($message);
    } 
}

// create ini array
$ini = config::getIniFileArray(_COS_PATH . "/config/config.ini", true);
//print_r($ini);
unset($ini['development']); //print_r($ini); die;
$ini['url'] = "mysql:dbname=$servername;host=localhost;charset=utf8";
$ini['server_name'] = $servername;
$ini['server_name_master'] = $servername;
$ini['server_redirect'] = $servername;
$init['db_init'] = "SET NAMES utf8";
//$ini['site_email'] = $row['email'];
$ini['domain'] = $servername;

// ini array to string
$str = config::arrayToIniFile($ini);
$site_ini = _COS_PATH . "/config/multi/$servername/config.ini";

// write ini string to file
if (file_exists($site_ini)) {
    $message = lang::translate('siteclone_rpc_ini_file_exists');
    die(nl2br($message));
} else {
    $res = file_put_contents($site_ini, $str);
    if (!$res) { 
        
        $message = lang::translate('siteclone_rpc_could_not_make_ini_file');
        die(nl2br($message));
    } else {        
        $message = lang::translate('siteclone_rpc_ini_file_created');
        echo nl2br($message);
    }
}

// create database
$db = new db();
$res = $db->createDB($servername);
if (!$res) {
    $message = lang::translate('siteclone_rpc_could_not_make_database');
    log::error($message);
    die(nl2br($message));
} else {
    
    $message = lang::translate('siteclone_rpc_database_created');
    echo nl2br($message);
}

// load base SQL
$path = _COS_PATH . "/scripts/default.sql";
$command = "mysql -u" . config::$vars['coscms_main']['username'] .
            " -p" . config::$vars['coscms_main']['password'] .
            " $servername < $path ";

exec($command, $output = array(), $ret = null);

if ($ret) {
    
    $message = lang::translate('siteclone_rpc_could_not_make_base_tables');
    log::error($message);
    die ($message);
} else {  
    $message = lang::translate('siteclone_rpc_base_tables_created');
    echo nl2br($message);
}

// install all profile modules
$profile = config::getModuleIni('siteclone_profile');
$command = "cd " . _COS_PATH  .' && ';
$command.= "./coscli.sh -d $servername profile --all-in $profile";
exec ($command, $output, $ret);

if ($ret) {
    // error in install
    
    $message = lang::translate('siteclone_rpc_could_not_install_modules');
    log::error($message);
    die(nl2br($message));
} else {
    
    $message = lang::translate('siteclone_rpc_all_modules_installed');
    echo nl2br($message);
}


// set template
$template = config::getModuleIni('siteclone_template');
$command = "cd " . _COS_PATH  .' && ';
$command.= "./coscli.sh -d $servername template --set $template";

exec ($command, $output, $ret);
if ($ret) {
    
    $message = lang::translate('siteclone_rpc_could_not_set_template');
    die(nl2br($message));
} else {
    
    $message = lang::translate('siteclone_rpc_template_set');
    echo nl2br($message);
}

// add super user
$command = "cd " . _COS_PATH  .' && ';
$command.= "./coscli.sh -d $servername useradd-direct --add-admin $row[email] $row[password]";
exec ($command, $output, $ret);
//print "Result create user = $ret";
if ($ret) {
    $message = lang::translate('siteclone_rpc_could_not_make_user');
    die(nl2br($message));
} else {
    $message = lang::translate('siteclone_rpc_user_created');
    echo nl2br($message);
}
// created files dir
$files_dir = _COS_PATH . "/htdocs/files/$servername";
if (!file_exists($files_dir)){
    @mkdir($files_dir);
}

$message = lang::translate('siteclone_site_created_final_message');
echo "<b>$message</b><br />\n";

// confirmation go to login
$message = lang::translate('siteclone_rpc_confirm_message');
$message= lang::translate('siteclone_rpc_link_text');

echo html::createLink(
        "http://$servername/account/login/index", 
        $message);
die;

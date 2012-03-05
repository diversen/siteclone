<?php

$clone = new siteclone();

// check for correct id. 
$row = $clone->getRowFromMD5($_GET['id']);
if (!$row) {
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
        echo "Can not make dir - set correct permissions e.g. ./coscli.sh file --chmod-files";
    } 
}

// create ini array
$ini = config::getIniFileArray(_COS_PATH . "/config/config.ini");
$ini['url'] = "mysql:dbname=$servername;host=localhost";
$ini['server_name'] = $servername;
$ini['server_redirect'] = $servername;
$ini['site_email'] = $row['email'];
$ini['domain'] = $servername;

// ini array to string
$str = config::arrayToIniFile($ini);
$site_ini = _COS_PATH . "/config/multi/$servername/config.ini";

// write ini string to file
if (file_exists($site_ini)) {
    echo "Ini file already exists";
} else {
    $res = file_put_contents($site_ini, $str);
    if (!$res) { 
        echo "Can not make ini file - set correct permissions e.g. ./coscli.sh file --chmod-files";
    } else {
        echo "File has been created";
    }
}

// create database
$db = new db();
$res = $db->createDB($servername);

$path = _COS_PATH . "/scripts/default.sql";
$command = "mysql -u" . config::$vars['coscms_main']['username'] .
            " -p" . config::$vars['coscms_main']['password'] .
            " $servername < $path ";

exec($command, $output = array(), $ret = null);
//print_r($output);
print "Result create: $ret<br />";

// install all profile modules
$profile = config::getModuleIni('siteclone_profile');
//$command = "./coscli.sh --domain=$servername profile --all-in $profile";
$command = "cd " . _COS_PATH  .' && ';
$command.= "./coscli.sh -d $servername profile --all-in $profile";
exec ($command, $output, $ret);
print "Result install modules = $ret<br />";
//print_r($output);
if (!$ret) {
    // error in install
} else {
    
}

// set template
$template = config::getModuleIni('siteclone_template');
$command = "cd " . _COS_PATH  .' && ';
$command.= "./coscli.sh -d $servername template --set $template";
//echo $command;
exec ($command, $output, $ret);
print "Result set template = $ret";

// add super user
$command = "cd " . _COS_PATH  .' && ';
echo $command.= "./coscli.sh -d $servername useradd_direct --add $row[email] $row[password]";
exec ($command, $output, $ret);
print "Result create user = $ret";

// created files dir
$files_dir = _COS_PATH . "/htdocs/files/$servername";
if (!file_exists($files_dir)){
    mkdir($files_dir);
}

// confirmation go to login
echo "You site has been build. You can now go to";
echo html::createLink("http://$servername/account/login/index", "Login on your new site with email and password");

die;
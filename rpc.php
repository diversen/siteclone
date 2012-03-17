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
        $message = "Administer has ¤#¤%& up. Can not make dir.<br /> ";
        $message.= "Ask him to set correct permissions<br />";
        $message.= "e.g. ./coscli.sh file --chmod-files<br />";
        die;
    } else {
        $message = "Created config dir<br />\n";
        echo $message;
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
    $message = "Ini file already exists.\n";
    $message.= "You site should already have created\n";
    die($message);
} else {
    $res = file_put_contents($site_ini, $str);
    if (!$res) { 
        $message = "Administer has #¤%!&¤ up<br />";
        $message.= "Can not make ini file<br />\n"; 
        $message.= "Ask him to set correct permissions with this command:<br />";
        $message.= "./coscli.sh file --chmod-files";
        die($message);
    } else {
        $message = "Config file has been created<br />\n";
        echo $message;
    }
}

// create database
$db = new db();
$res = $db->createDB($servername);
if (!$res) {
    $message = "Could not create database. Something is wrong.<br />\n";
    cos_error_log($message);
    die($message);
} else {
    $message = "Database has been created";
    echo $message;
}

// load base SQL
$path = _COS_PATH . "/scripts/default.sql";
$command = "mysql -u" . config::$vars['coscms_main']['username'] .
            " -p" . config::$vars['coscms_main']['password'] .
            " $servername < $path ";

exec($command, $output = array(), $ret = null);

if ($ret) {
    $message = "Could not create base DB tables.";
    $message.= "Something is not right!";
    cos_error_log($message);
    die ($message);
} else {
    $message = "Base Tables created<br />";
    echo $message;
}

// install all profile modules
$profile = config::getModuleIni('siteclone_profile');
$command = "cd " . _COS_PATH  .' && ';
$command.= "./coscli.sh -d $servername profile --all-in $profile";
exec ($command, $output, $ret);

if ($ret) {
    // error in install
    $message = "Could not install all modules. Site will not work!<br />\n";
    cos_error_log($message);
    die($message);
} else {
    $message = "All modules was installed<br />";
    echo $message;
}

// set template
$template = config::getModuleIni('siteclone_template');
$command = "cd " . _COS_PATH  .' && ';
$command.= "./coscli.sh -d $servername template --set $template";

exec ($command, $output, $ret);
if ($ret) {
    $message = "Could not set default template<br />";
    echo $message;
} else {
    $message = "Default template has been set<br />\n";
    echo $message;
}

// add super user
$command = "cd " . _COS_PATH  .' && ';
$command.= "./coscli.sh -d $servername useradd_direct --add $row[email] $row[password]";
exec ($command, $output, $ret);
//print "Result create user = $ret";
if ($ret) {
    $message = "Could not create your suer user<br />\n";
} else {
    $message = "Super User has been created<br />\n";
}
// created files dir
$files_dir = _COS_PATH . "/htdocs/files/$servername";
if (!file_exists($files_dir)){
    @mkdir($files_dir);
}

// confirmation go to login
echo "You site has been build. You can now go to<br />\n";
echo html::createLink(
        "http://$servername/account/login/index", 
        "Login on your new site with email and password");
die;
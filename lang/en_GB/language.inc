<?php

// Translation of file ./modules/siteclone/model.siteclone.inc

$_COS_LANG_MODULE['siteclone_legend'] = 'New Site Information';
$_COS_LANG_MODULE['siteclone_label_sitename'] = 'Sitename (a-z and 0-9 and at least 5 chars)';
$_COS_LANG_MODULE['siteclone_label_email'] = 'Email (have to be valid)';
$_COS_LANG_MODULE['siteclone_label_password'] = 'Enter Password';
$_COS_LANG_MODULE['siteclone_label_password2'] = 'Retype Password';
$_COS_LANG_MODULE['siteclone_submit_text'] = 'Submit';
$_COS_LANG_MODULE['siteclone_confirm_legend'] = 'Confirm Creation';
$_COS_LANG_MODULE['siteclone_error_sitename_length'] = 'Sitename needs to be at least 5 chars long';
$_COS_LANG_MODULE['siteclone_error_sitename_not_valid'] = 'Sitename not valid';
$_COS_LANG_MODULE['siteclone_error_sitename_exists'] = 'Sitename already exists';
$_COS_LANG_MODULE['siteclone_error_email_exists'] = 'Email already exists';
$_COS_LANG_MODULE['siteclone_error_password_length'] = 'Password needs to be at least 7 chars long';
$_COS_LANG_MODULE['siteclone_error_password_no_match'] = 'Passwords does not match';
$_COS_LANG_MODULE['siteclone_error_invalid_email'] = 'Not a valid email';
$_COS_LANG_MODULE['siteclone_error_incorrect_captcha'] = 'Please enter correct captcha';

$_COS_LANG_MODULE['siteclone_email_subject'] = 'Creation of site';
$_COS_LANG_MODULE['siteclone_no_such_id'] = 'siteclone_no_such_id';
$_COS_LANG_MODULE['siteclone_already_validated'] = 'siteclone_already_validated';

$_COS_LANG_MODULE['siteclone_confirm_email'] = 'An email has been sent, please check your mailbox in a few minutes for futher instructions';
$_COS_LANG_MODULE['siteclone_confirm_email_error'] = 'An error was encountered while trying to send an email. Please try to create a new site later';

$_COS_LANG_MODULE['siteclone_confirm_html_title'] = 'siteclone_confirm_html_title';
$_COS_LANG_MODULE['siteclone_rpc_created_config_dir'] = "Created config dir\n";
$_COS_LANG_MODULE['siteclone_rpc_ini_file_exists'] = "Ini file already exists.\n";

$message = "Administer has #¤%!&¤ up\n";
$message.= "Can not make ini file\n"; 
$message.= "Ask him to set correct permissions with this command:\n";
$message.= "./coscli.sh file --chmod-files\n";

$_COS_LANG_MODULE['siteclone_rpc_could_not_make_ini_file'] = $message;

$message = "Config file has been created\n";

$_COS_LANG_MODULE['siteclone_rpc_ini_file_created'] = $message;

$message = "Could not create database. Something is wrong.\n";

$_COS_LANG_MODULE['siteclone_rpc_could_not_make_database'] = $message;

$message = "Database has been created\n";
$_COS_LANG_MODULE['siteclone_rpc_database_created'] = $message;

$message = "Could not create base DB tables.\n";
$message.= "Something is not right.\n";

$_COS_LANG_MODULE['siteclone_rpc_could_not_make_base_tables'] = $message;

$message = "Base Tables created\n";

$_COS_LANG_MODULE['siteclone_rpc_base_tables_created'] = $message;

$message = "Could not install all modules. Site will not work!\n";

$_COS_LANG_MODULE['siteclone_rpc_could_not_install_modules'] = $message;

$message = "All modules was installed\n";

$_COS_LANG_MODULE['siteclone_rpc_all_modules_installed'] = $message;


$message = "Could not set default template\n";
$_COS_LANG_MODULE['siteclone_rpc_could_not_set_template'] = $message;

$message = "Default template has been set\n";
$_COS_LANG_MODULE['siteclone_rpc_template_set'] = $message;


$message = "Could not create your user\n";
$_COS_LANG_MODULE['siteclone_rpc_could_not_make_user'] = $message;

$message = "User has been created\n";
$_COS_LANG_MODULE['siteclone_rpc_user_created'] = $message;

$message = "You site has been build. You can now go to\n";
$_COS_LANG_MODULE['siteclone_rpc_confirm_message'] = $message;

$message = 'Login on your new site with email and password';
$_COS_LANG_MODULE['siteclone_rpc_link_text'] = $message;
//"Administer has ¤#¤%& up. Can not make config dir.\nAsk him to set correct permissions\ne.g. ./coscli.sh file --chmod-files\n"
$_COS_LANG_MODULE['siteclone_rpc_please_wait_message'] = 'Please Wait. This may take a minute or two ...';
$_COS_LANG_MODULE['siteclone_rpc_can_not_make_dir'] = "Administer has ¤#¤%& up. Can not make config dir.\nAsk him to set correct permissions\ne.g. ./coscli.sh file --chmod-files\n";

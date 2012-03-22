<?php

// Translation of file ./modules/siteclone/model.siteclone.inc

$_COS_LANG_MODULE['siteclone_legend'] = 'Opret website';
$_COS_LANG_MODULE['siteclone_label_sitename'] = 'Domæne navn (kun a-z og 0-9 - mindst 5 tegn)';
$_COS_LANG_MODULE['siteclone_label_email'] = 'Indtast en gyldig email';
$_COS_LANG_MODULE['siteclone_label_password'] = 'Password';
$_COS_LANG_MODULE['siteclone_label_password2'] = 'Gentag password';
$_COS_LANG_MODULE['siteclone_submit_text'] = 'Opret';
$_COS_LANG_MODULE['siteclone_confirm_legend'] = 'Bekræft oprettelse';
$_COS_LANG_MODULE['siteclone_error_sitename_length'] = 'Domæne navn skal mindst 5 tegn';
$_COS_LANG_MODULE['siteclone_error_sitename_not_valid'] = 'Ikke et gyldigt domæne navn';
$_COS_LANG_MODULE['siteclone_error_sitename_exists'] = 'Domænet eksisterer';
$_COS_LANG_MODULE['siteclone_error_email_exists'] = 'Email eksisterer allerede';
$_COS_LANG_MODULE['siteclone_error_password_length'] = 'Password skal være mindst 7 tegn';
$_COS_LANG_MODULE['siteclone_error_password_no_match'] = 'Passwords matcher ikke';
$_COS_LANG_MODULE['siteclone_error_invalid_email'] = 'Ugyldig email';
$_COS_LANG_MODULE['siteclone_error_incorrect_captcha'] = 'Ikke et korrekt svar til captcha test';
$_COS_LANG_MODULE['siteclone_email_subject'] = 'Oprettelse af site';
// Translation of file ./modules/siteclone/rpc.php

$_COS_LANG_MODULE['siteclone_no_such_id'] = 'ID ikke fundet i database';
$_COS_LANG_MODULE['siteclone_already_validated'] = 'Domænet er allerede valideret';
// Translation of file ./modules/siteclone/index.php

$_COS_LANG_MODULE['siteclone_confirm_email'] = 'Der er afsendt en email. Check din mailbox og følg instruktioner';
$_COS_LANG_MODULE['siteclone_confirm_email_error'] = 'Der opstod en fejl og systemet kunne ikke afsende en email. Prøv at oprette et site senere';

$_COS_LANG_MODULE['siteclone_confirm_html_title'] = 'Bekræft oprettelse af site';
$_COS_LANG_MODULE['siteclone_rpc_created_config_dir'] = "Skabte konfigurations dir\n";
$_COS_LANG_MODULE['siteclone_rpc_ini_file_exists'] = "Konfigurations fil eksisterer allerede.\n";

$message = "Tell administer #¤%!&¤\n";
$message.= "Kan kke skabe ini fil\n"; 
$message.= "Sandsynligvis fordi web serveren ikke har de rette rettigheder. Prøv med:\n";
$message.= "./coscli.sh file --chmod-files\n";

$_COS_LANG_MODULE['siteclone_rpc_could_not_make_ini_file'] = $message;

$message = "Konfigurations fil blev skabt\n";

$_COS_LANG_MODULE['siteclone_rpc_ini_file_created'] = $message;

$message = "Kunne ikke oprette database.\n";

$_COS_LANG_MODULE['siteclone_rpc_could_not_make_database'] = $message;

$message = "Database blev oprettet\n";
$_COS_LANG_MODULE['siteclone_rpc_database_created'] = $message;

$message = "Kunne ikke oprettet basis tabeller i database.\n";
//$message.= "Something is not right.\n";

$_COS_LANG_MODULE['siteclone_rpc_could_not_make_base_tables'] = $message;

$message = "Basis tabeller blev oprettet i database\n";

$_COS_LANG_MODULE['siteclone_rpc_base_tables_created'] = $message;

$message = "Kunne ikke installere moduler!\n";

$_COS_LANG_MODULE['siteclone_rpc_could_not_install_modules'] = $message;

$message = "All moduler blev installeret\n";

$_COS_LANG_MODULE['siteclone_rpc_all_modules_installed'] = $message;


$message = "Kunne ikke sætte standard template\n";
$_COS_LANG_MODULE['siteclone_rpc_could_not_set_template'] = $message;

$message = "Standard template blev sat\n";
$_COS_LANG_MODULE['siteclone_rpc_template_set'] = $message;


$message = "Kunne ikke skabe bruger\n";
$_COS_LANG_MODULE['siteclone_rpc_could_not_make_user'] = $message;

$message = "Bruger blev oprettet\n";
$_COS_LANG_MODULE['siteclone_rpc_user_created'] = $message;

$message = "Dit site blev oprettet\n";
$_COS_LANG_MODULE['siteclone_rpc_confirm_message'] = $message;

$message = 'Login med email og password';
$_COS_LANG_MODULE['siteclone_rpc_link_text'] = $message;
//"Administer has ¤#¤%& up. Can not make config dir.\nAsk him to set correct permissions\ne.g. ./coscli.sh file --chmod-files\n"
$_COS_LANG_MODULE['siteclone_rpc_please_wait_message'] = 'Vent veligst. Dette kan tage op til et minut eller to ...';
$_COS_LANG_MODULE['siteclone_rpc_can_not_make_dir'] = "Kunne ikke oprettet konfigurations dir\nBed ham om at sætte korrekte tilladelser\nfx:\n./coscli.sh file --chmod-files\n";

$_COS_LANG_MODULE['siteclone_clone_site_html_title'] = 'Opret gratis website';

$_COS_LANG_MODULE['siteclone_site_meta_desc'] = 'Simple og brugervenligt CMS - ganske gratis!';

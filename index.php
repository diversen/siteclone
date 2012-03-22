<?php


template::setTitle(lang::translate('siteclone_clone_site_html_title'));
template::setMeta(array('description' => lang::translate('siteclone_site_meta_desc')));

http::prg();
$clone = new siteclone();
if (!empty($_POST)) {   
    $clone->validate();
    $clone->validateCaptcha();
    if (!empty($clone->errors)) {
        view_form_errors($clone->errors);
        $clone->form(); 
    } else {
        //save_post('siteclone_post');
        $res = $clone->doConfirm();
        //die;
        if ($res) {
            view_confirm(lang::translate('siteclone_confirm_email'));
        } else {
            view_form_errors(lang::translate('siteclone_confirm_email_error'));
            
        }        
    }
} else {
    $clone->form(); 
}



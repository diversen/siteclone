<?php

include_once "coslib/captcha.php";
include_once "coslib/random.php";

class siteclone {
    
    public function form () {        
        $options = array ('required' => true);
        $form = new HTML();
        $form->init(array(), 'submit');
        
        $form->formStartAry(array ('id' => 'siteclone_form'));
        $form->legend(lang::translate('siteclone_legend'));
        $form->label('sitename', lang::translate('siteclone_label_sitename'), $options);
        $form->text('sitename');
        $form->label('email', lang::translate('siteclone_label_email'), $options);
        $form->text('email');
        $form->label('password1', lang::translate('siteclone_label_password'), $options);
        $form->password('password1');
        $form->label('password2', lang::translate('siteclone_label_password2'), $options);
        $form->password('password2');
        $form->label('captcha', captcha::createCaptcha(), $options);
        $form->text('captcha');
        $form->label('submit');
        $form->submit('submit', lang::translate('siteclone_submit_text'));
        $form->formEnd();
        echo $form->getStr();
    }
    
    public function confirmForm () {
        $form = new HTML();
        $form->formStartAry(array ('id' => 'siteclone_form'));
        $form->legend(lang::translate('siteclone_confirm_legend'));       
        $options = array ('required' => true);
        $form->label('captcha', captcha::createCaptcha(), $options);
        $form->text('captcha');
        $form->label('submit');
        $form->submit('submit', lang::translate('siteclone_submit_text'));
        $form->formEnd();
        echo $form->getStr();
    }
    
    public function domainExists ($domain) {
        $domain = $domain . '.' . config::getMainIni('server_name');
        $file = _COS_PATH . "/config/multi/$domain/config.ini";
        $res = file_exists($file);
        if ($res) return true;
        $db = new db();
        $row = $db->selectOne('siteclone', 'sitename', $_POST['sitename']);
        //print_r($row); die;
        if (!empty($row)) {
            return true;
        }
        return false;        
    }
    
        
    
    public function emailExist () {
        $db = new db();
        $row = $db->selectOne('siteclone', 'email', $_POST['email']);
        //print_r($row); die;
        if (!empty($row)) {
            return true;
        }
        return false;   
    }
    
    public $errors = array ();
    public function validate () {
        if (strlen($_POST['sitename']) < 5){
            $this->errors['sitename_length'] = lang::translate('siteclone_error_sitename_length');
        }
        
        if (strlen($_POST['sitename']) > 15){
            $this->errors['sitename_length'] = lang::translate('siteclone_error_sitename_length');
        }
        
        if (!preg_match('/^[a-z1-9]+$/', $_POST['sitename'])){
            $this->errors['sitename_not_valid'] = lang::translate('siteclone_error_sitename_not_valid');
        }
        
        if ($this->domainExists($_POST['sitename'])) {
            $this->errors['sitename_exists'] = lang::translate('siteclone_error_sitename_exists');
        }
        
        if ($this->emailExist($_POST['email'])){
            $this->errors['email'] = lang::translate('siteclone_error_email_exists');
        }
        if (strlen($_POST['password1']) < 7){
            $this->errors['password1'] = lang::translate('siteclone_error_password_length');
        }
        if ($_POST['password1'] != $_POST['password2']){
            $this->errors['password1'] = lang::translate('siteclone_error_password_no_match');
        }
        if (!cosValidate::validateEmailAndDomain($_POST['email'])){
            $this->errors['email'] = lang::translate('siteclone_error_invalid_email');
        }
        
        $_POST = html::specialEncode($_POST);
    }
    
    public function validateCaptcha () {
        if (!captcha::checkCaptcha(trim($_POST['captcha']))){
            $this->errors['captcha'] = lang::translate('siteclone_error_incorrect_captcha');
        }
    }
    

    
    public static function doConfirm () {
        $lang = config::getMainIni('language');
        $md5 = md5(random::string(32));
        $sitename = self::getSiteName($_POST['sitename']);
        
        db::$dbh->beginTransaction();
        $db = new db();
        $values = db::prepareToPost();
        $values['md5_key'] = $md5;
        $values['password'] = md5(html::specialDecode($values['password1']));
        unset($values['password1']);
        $db->insert('siteclone', $values);
        
        // send email
        $vars = array (
            'sitename' => $sitename, 
            'confirm_link' => self::getConfirmLink($md5),
            'sender_site' => self::getSiteName()
        );
        $subject = lang::translate('siteclone_email_subject');
        $email = templateView::get('siteclone', "lang/$lang/confirm_email", $vars);
        
        if (mail_utf8($_POST['email'], $subject, $email)){
            db::$dbh->commit();
            return true;
        } else {
            db::$dbh->rollBack();
            return false;
        }        
    }
    
    public static function getSiteName ($newsite = '') {
        $ssl = config::getMainIni('server_force_ssl');
        if ($ssl) {
            $str = "https://";
        } else {
            $str = "http://";
        }
        
        if (!empty($newsite)) {
            $str.= $newsite . ".";
        }
        
        return $str . config::getMainIni('server_name');
    }
    
    public static function getConfirmLink ($random) {
        $str = self::getSiteName();
        $str.= "/siteclone/confirm?id=$random";
        return $str;
    }
    
    public function getRowFromMD5 ($md5) {
        $db = new db();
        return $db->selectOne('siteclone', 'md5_key', $md5);
        
        
    }
    
    public function generateSite () {
        // create ini file
        // create DB
        // install modules
        // add user       
    }
    
    public static function createIniFile () {
        
    }
}


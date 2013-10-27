### About

The is a CosCMS module for cloning a complete site. It let's users sign
up and then it sends a confirmation mail. In the confirmation mail he 
is provided a clone link. 

When the user press the link the new site is created. 


### Config

    ; modules which should not be installed in the clone process
    siteclone_exclude[0] = "siteclone"
    siteclone_exclude[1] = "newsletter"
    ; the profile to clone
    siteclone_profile = "default"
    ; the default template
    siteclone_template = "zimpleza"

### Apache2 virtual host example

	<VirtualHost *:80>
	    ServerAdmin webmaster@example.com
	    ServerName  coscms.org
	    ServerAlias *.coscms.org
	
	    # Indexes + Directory Root.
	    Include /home/dennis/apache.conf
	    DirectoryIndex index.php
	    DocumentRoot /home/dennis/www/os-cms.dk/htdocs
	  
	    <Directory /home/dennis/www/os-cms.dk/htdocs>
	        RewriteEngine on
	        RewriteBase /
	        RewriteCond %{REQUEST_FILENAME} !-f
	        RewriteCond %{REQUEST_FILENAME} !-d
	        RewriteRule ^(.*)$ index.php?q=$1 [L,QSA]
	    </Directory>
	   
	    ErrorLog  /home/dennis/www/os-cms.dk/logs/error.log
	    CustomLog /home/dennis/www/os-cms.dk/logs/access.log combined
	</VirtualHost>


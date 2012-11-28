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


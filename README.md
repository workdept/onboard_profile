

Install
-------

With PHP>5.4 and Drush 6:

```
drush make --working-copy https://raw.github.com/bnchdrff/onboard_profile/7.x-1.x/distro.make onboard_webroot
cd onboard_webroot
mysql -uroot -e 'create database onboard_test'
drush site-install onboard_profile  --account-name=admin --account-pass=admin --db-url=mysql://root@localhost/onboard_test --yes
drush en onboard_types views_ui context_ui field_ui diff admin_menu adminimal_admin_menu
# Organic Groups role permissions for node access get clobbered during the 
# site install.  Revert the feature to have them set correctly
drush fr onboard_types --yes
drush cc all
drush php-eval 'node_access_rebuild();'
drush runserver --server=builtin 8080
```

Test
----

A test suite lives in `tests/`. Tests are run using [PhantomJS](http://phantomjs.org/), [Behat](http://behat.org), [Mink Extension](http://extensions.behat.org/mink/), and [Drupal Extension](https://github.com/jhedstrom/drupalextension).

After you do everything in the Install section above, you can run tests! Make sure the server is running on port 8080.

```
# install phantomjs
# npm install -g phantomjs works well!
# run phantomjs:
phantomjs --webdriver=8643 &
# set up behat/mink
cd profiles/onboard_profile/tests
curl -s https://getcomposer.org/installer | php
php composer.phar install # you need the php5-curl extension, among other extensions!
# make sure behat has the drupalextension step definitions.. if nothing shows up, run:
#./bin/behat --init
./bin/behat -dl
# run tests
./bin/behat features/
```

License
-------

Copyright 2013, Benjamin Chodoroff. This software is distributed under the terms of the GNU General Public License.

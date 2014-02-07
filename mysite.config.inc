<?php
/**
 * @file mysite.config.inc 
 *  Returns configuration information for my particular instance of the
 *  minimal_ci distro.
 */

function site_make_config() {
  $conf = array();

  /**
   * Target directory for site build. Defaults to "docroot" if nothing is set.
   *
   * This directory will be removed entirely and replaced with a fresh Drush make
   * build.
   */
  $conf['target'] = 'docroot';
  
  /**
   * Specify build file (highest parent make file).
   */
   $conf['build_file'] = 'build-minimal_ci.make';

  /**
   * Replace vanilla downloads/checkouts from drush make with git subtrees for projects you maintain.
   *
   * Git subtrees are added to the projects directory, based on the version
   * specified in the site's make file. Then the project download pulled in by
   * drush make will be replaced with a symlink to the git subtree.
   *
   * $conf['subtrees']['example_project']['path'] = 'docroot/sites/all/modules/contrib/example_project';
   * $conf['subtrees']['example_project']['uri'] = 'http://git.drupal.org/project/example_project.git';
   * $conf['subtrees']['example_project']['branch'] = '7.x-1.x';
   *
   * required params:
   *  - path, path to where drush make downloads a copy of this project
   *    to be replaced with a symlink to your git subtree
   *  - uri, local or remote git repo
   *  - branch, branch to be used for initial git subtree add
   */
  $conf['subtrees']['minimal_ci']['path'] = 'docroot/profiles/minimal_ci';
  $conf['subtrees']['minimal_ci']['uri'] = 'https://github.com/bryanhirsch/minimal_ci.git';
  $conf['subtrees']['minimal_ci']['branch'] = '7.x-1.x';
  $conf['subtrees']['minimal_ci']['squash'] = FALSE;

  /**
   * Specify any custom commands you want to run at the end of site setup.
   *
   * These commands are run after drush make is done rebuilding your project, and
   * after drush make-site has finished checking out subtrees and creating symlinks.
   *
   * For example:
   *  - re-symlink your sites directory
   *  - checkout your modified .htaccess or robots.txt before committing changes
   *  - git commit
   */
  $conf['commands'][] = "rm -rf docroot/sites/default; cd docroot/sites; ln -s ../../symlink-these/default default";
  $conf['commands'][] = "rm -rf docroot/.htaccess; cd docroot/; ln -s ../symlink-these/.htaccess .htaccess";
  $conf['commands'][] = "rm -rf docroot/robots.txt; cd docroot/; ln -s ../symlink-these/robots.txt robots.txt";

  return $conf;
}

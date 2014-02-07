api = 2
core = 7.x
includes[core] = drupal-org-core.make
includes[contrib] = drupal-org.make

projects[minimal_ci][type] = "profile"
projects[minimal_ci][download][type] = "git"
projects[minimal_ci][download][url] = "https://github.com/bryanhirsch/minimal_ci.git"
projects[minimal_ci][download][branch] = "7.x-1.x"

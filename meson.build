project('ite', 'c',
  version : '0.1',
  meson_version: '>= 0.60.0',
  default_options : ['warning_level=3'])

executable('ite',
           'main.c', 'iteapp.c', 'iteappwin.c',
          dependencies: [ dependency('gtk4') ],
          install : true
          )

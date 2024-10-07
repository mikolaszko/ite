project('ite', 'c',
  version : '0.1',
  meson_version: '>= 0.60.0',
  default_options : ['warning_level=3'])

gnome = import('gnome')
uiresources = gnome.compile_resources(
  'ui-resources', 'ite.gresource.xml',
  source_dir: '.',
  c_name: 'ui'
)
sourcefiles = files('main.c', 'iteapp.c', 'iteappwin.c')
gtkdep = dependency('gtk4')

executable('ite',
          sourcefiles,
          uiresources, 
          dependencies: gtkdep,
          install : false
          )

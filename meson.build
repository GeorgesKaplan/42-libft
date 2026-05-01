project(
  'libft',
  'c',
  meson_version: '>= 0.63.0',
  version: '0.0.1',
)

includes = include_directories('includes')

sources = files(
  'srcs/libft_char_checker1.c',
  'srcs/libft_char_checker2.c',
  'srcs/libft_converters1.c',
  'srcs/libft_gnl.c',
  'srcs/libft_list_utils1.c',
  'srcs/libft_list_utils2.c',
  'srcs/libft_memory_utils1.c',
  'srcs/libft_memory_utils2.c',
  'srcs/libft_printf_utils1.c',
  'srcs/libft_printf_utils2.c',
  'srcs/libft_printf_utils3.c',
  'srcs/libft_put_fd.c',
  'srcs/libft_split.c',
  'srcs/libft_split_keep.c',
  'srcs/libft_split_keep_utils.c',
  'srcs/libft_str_checker1.c',
  'srcs/libft_string_utils1.c',
  'srcs/libft_string_utils2.c',
  'srcs/libft_string_utils3.c',
  'srcs/libft_string_utils4.c',
  'srcs/libft_string_utils5.c',
)

libft = library(
  'ft',
  sources,
  include_directories: includes,
  install: true,
)

libft_dep = declare_dependency(include_directories : includes, link_with: libft)
meson.override_dependency('libft', libft_dep)
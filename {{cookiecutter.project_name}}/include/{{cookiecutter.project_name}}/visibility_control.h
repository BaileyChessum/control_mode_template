#ifndef {{cookiecutter.project_name | upper}}__VISIBILITY_CONTROL_H_
#define {{cookiecutter.project_name | upper}}__VISIBILITY_CONTROL_H_

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define {{cookiecutter.project_name | upper}}_EXPORT __attribute__ ((dllexport))
    #define {{cookiecutter.project_name | upper}}_IMPORT __attribute__ ((dllimport))
  #else
    #define {{cookiecutter.project_name | upper}}_EXPORT __declspec(dllexport)
    #define {{cookiecutter.project_name | upper}}_IMPORT __declspec(dllimport)
  #endif
  #ifdef {{cookiecutter.project_name | upper}}_BUILDING_LIBRARY
    #define {{cookiecutter.project_name | upper}}_PUBLIC {{cookiecutter.project_name | upper}}_EXPORT
  #else
    #define {{cookiecutter.project_name | upper}}_PUBLIC {{cookiecutter.project_name | upper}}_IMPORT
  #endif
  #define {{cookiecutter.project_name | upper}}_PUBLIC_TYPE {{cookiecutter.project_name | upper}}_PUBLIC
  #define {{cookiecutter.project_name | upper}}_LOCAL
#else
  #define {{cookiecutter.project_name | upper}}_EXPORT __attribute__ ((visibility("default")))
  #define {{cookiecutter.project_name | upper}}_IMPORT
  #if __GNUC__ >= 4
    #define {{cookiecutter.project_name | upper}}_PUBLIC __attribute__ ((visibility("default")))
    #define {{cookiecutter.project_name | upper}}_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define {{cookiecutter.project_name | upper}}_PUBLIC
    #define {{cookiecutter.project_name | upper}}_LOCAL
  #endif
  #define {{cookiecutter.project_name | upper}}_PUBLIC_TYPE
#endif

#endif  // {{cookiecutter.project_name | upper}}__VISIBILITY_CONTROL_H_

#ifndef EXPORT_H

#ifdef ENGINE_EXPORT
#define ENGINE_API __declspec(dllexport) //clase para exportacion
#else
#define ENGINE_API __declspec(dllimport)  // especifica clase para importacion
#endif // ENGINE_EXPORTS

#endif // !EXPORT_H




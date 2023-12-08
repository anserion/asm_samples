; Extensions 
 GLU_EXT_object_space_tess         equ 1
 GLU_EXT_nurbs_tessellator         equ  1

; Boolean 
 GLU_FALSE                         equ  0
 GLU_TRUE                          equ  1

; Version 
 GLU_VERSION_1_1                   equ  1
 GLU_VERSION_1_2                   equ  1
 GLU_VERSION_1_3                   equ  1

; StringName 
 GLU_VERSION                        equ 100800
 GLU_EXTENSIONS                     equ 100801

; ErrorCode 
 GLU_INVALID_ENUM                   equ 100900
 GLU_INVALID_VALUE                  equ 100901
 GLU_OUT_OF_MEMORY                  equ 100902
 GLU_INVALID_OPERATION              equ 100904

; NurbsDisplay 
;      GLU_FILL 
 GLU_OUTLINE_POLYGON                equ 100240
 GLU_OUTLINE_PATCH                  equ 100241

; NurbsCallback 
 GLU_NURBS_ERROR                    equ 100103
 GLU_ERROR                          equ 100103
 GLU_NURBS_BEGIN                    equ 100164
 GLU_NURBS_BEGIN_EXT                equ 100164
 GLU_NURBS_VERTEX                   equ 100165
 GLU_NURBS_VERTEX_EXT               equ 100165
 GLU_NURBS_NORMAL                   equ 100166
 GLU_NURBS_NORMAL_EXT               equ 100166
 GLU_NURBS_COLOR                    equ 100167
 GLU_NURBS_COLOR_EXT                equ 100167
 GLU_NURBS_TEXTURE_COORD            equ 100168
 GLU_NURBS_TEX_COORD_EXT            equ 100168
 GLU_NURBS_END                      equ 100169
 GLU_NURBS_END_EXT                  equ 100169
 GLU_NURBS_BEGIN_DATA               equ 100170
 GLU_NURBS_BEGIN_DATA_EXT           equ 100170
 GLU_NURBS_VERTEX_DATA              equ 100171
 GLU_NURBS_VERTEX_DATA_EXT          equ 100171
 GLU_NURBS_NORMAL_DATA              equ 100172
 GLU_NURBS_NORMAL_DATA_EXT          equ 100172
 GLU_NURBS_COLOR_DATA               equ 100173
 GLU_NURBS_COLOR_DATA_EXT           equ 100173
 GLU_NURBS_TEXTURE_COORD_DATA       equ 100174
 GLU_NURBS_TEX_COORD_DATA_EXT       equ 100174
 GLU_NURBS_END_DATA                 equ 100175
 GLU_NURBS_END_DATA_EXT             equ 100175

; NurbsError 
 GLU_NURBS_ERROR1                   equ 100251
 GLU_NURBS_ERROR2                   equ 100252
 GLU_NURBS_ERROR3                   equ 100253
 GLU_NURBS_ERROR4                   equ 100254
 GLU_NURBS_ERROR5                   equ 100255
 GLU_NURBS_ERROR6                   equ 100256
 GLU_NURBS_ERROR7                   equ 100257
 GLU_NURBS_ERROR8                   equ 100258
 GLU_NURBS_ERROR9                   equ 100259
 GLU_NURBS_ERROR10                  equ 100260
 GLU_NURBS_ERROR11                  equ 100261
 GLU_NURBS_ERROR12                  equ 100262
 GLU_NURBS_ERROR13                  equ 100263
 GLU_NURBS_ERROR14                  equ 100264
 GLU_NURBS_ERROR15                  equ 100265
 GLU_NURBS_ERROR16                  equ 100266
 GLU_NURBS_ERROR17                  equ 100267
 GLU_NURBS_ERROR18                  equ 100268
 GLU_NURBS_ERROR19                  equ 100269
 GLU_NURBS_ERROR20                  equ 100270
 GLU_NURBS_ERROR21                  equ 100271
 GLU_NURBS_ERROR22                  equ 100272
 GLU_NURBS_ERROR23                  equ 100273
 GLU_NURBS_ERROR24                  equ 100274
 GLU_NURBS_ERROR25                  equ 100275
 GLU_NURBS_ERROR26                  equ 100276
 GLU_NURBS_ERROR27                  equ 100277
 GLU_NURBS_ERROR28                  equ 100278
 GLU_NURBS_ERROR29                  equ 100279
 GLU_NURBS_ERROR30                  equ 100280
 GLU_NURBS_ERROR31                  equ 100281
 GLU_NURBS_ERROR32                  equ 100282
 GLU_NURBS_ERROR33                  equ 100283
 GLU_NURBS_ERROR34                  equ 100284
 GLU_NURBS_ERROR35                  equ 100285
 GLU_NURBS_ERROR36                  equ 100286
 GLU_NURBS_ERROR37                  equ 100287

; NurbsProperty 
 GLU_AUTO_LOAD_MATRIX               equ 100200
 GLU_CULLING                        equ 100201
 GLU_SAMPLING_TOLERANCE             equ 100203
 GLU_DISPLAY_MODE                   equ 100204
 GLU_PARAMETRIC_TOLERANCE           equ 100202
 GLU_SAMPLING_METHOD                equ 100205
 GLU_U_STEP                         equ 100206
 GLU_V_STEP                         equ 100207
 GLU_NURBS_MODE                     equ 100160
 GLU_NURBS_MODE_EXT                 equ 100160
 GLU_NURBS_TESSELLATOR              equ 100161
 GLU_NURBS_TESSELLATOR_EXT          equ 100161
 GLU_NURBS_RENDERER                 equ 100162
 GLU_NURBS_RENDERER_EXT             equ 100162

; NurbsSampling 
 GLU_OBJECT_PARAMETRIC_ERROR        equ 100208
 GLU_OBJECT_PARAMETRIC_ERROR_EXT    equ 100208
 GLU_OBJECT_PATH_LENGTH             equ 100209
 GLU_OBJECT_PATH_LENGTH_EXT         equ 100209
 GLU_PATH_LENGTH                    equ 100215
 GLU_PARAMETRIC_ERROR               equ 100216
 GLU_DOMAIN_DISTANCE                equ 100217

; NurbsTrim 
 GLU_MAP1_TRIM_2                    equ 100210
 GLU_MAP1_TRIM_3                    equ 100211

; QuadricDrawStyle 
 GLU_POINT                          equ 100010
 GLU_LINE                           equ 100011
 GLU_FILL                           equ 100012
 GLU_SILHOUETTE                     equ 100013

; QuadricCallback 
;      GLU_ERROR 

; QuadricNormal 
 GLU_SMOOTH                         equ 100000
 GLU_FLAT                           equ 100001
 GLU_NONE                           equ 100002

; QuadricOrientation 
 GLU_OUTSIDE                        equ 100020
 GLU_INSIDE                         equ 100021

; TessCallback 
 GLU_TESS_BEGIN                     equ 100100
 GLU_BEGIN                          equ 100100
 GLU_TESS_VERTEX                    equ 100101
 GLU_VERTEX                         equ 100101
 GLU_TESS_END                       equ 100102
 GLU_END                            equ 100102
 GLU_TESS_ERROR                     equ 100103
 GLU_TESS_EDGE_FLAG                 equ 100104
 GLU_EDGE_FLAG                      equ 100104
 GLU_TESS_COMBINE                   equ 100105
 GLU_TESS_BEGIN_DATA                equ 100106
 GLU_TESS_VERTEX_DATA               equ 100107
 GLU_TESS_END_DATA                  equ 100108
 GLU_TESS_ERROR_DATA                equ 100109
 GLU_TESS_EDGE_FLAG_DATA            equ 100110
 GLU_TESS_COMBINE_DATA              equ 100111

; TessContour 
 GLU_CW                             equ 100120
 GLU_CCW                            equ 100121
 GLU_INTERIOR                       equ 100122
 GLU_EXTERIOR                       equ 100123
 GLU_UNKNOWN                        equ 100124

; TessProperty 
 GLU_TESS_WINDING_RULE              equ 100140
 GLU_TESS_BOUNDARY_ONLY             equ 100141
 GLU_TESS_TOLERANCE                 equ 100142

; TessError 
 GLU_TESS_ERROR1                    equ 100151
 GLU_TESS_ERROR2                    equ 100152
 GLU_TESS_ERROR3                    equ 100153
 GLU_TESS_ERROR4                    equ 100154
 GLU_TESS_ERROR5                    equ 100155
 GLU_TESS_ERROR6                    equ 100156
 GLU_TESS_ERROR7                    equ 100157
 GLU_TESS_ERROR8                    equ 100158
 GLU_TESS_MISSING_BEGIN_POLYGON     equ 100151
 GLU_TESS_MISSING_BEGIN_CONTOUR     equ 100152
 GLU_TESS_MISSING_END_POLYGON       equ 100153
 GLU_TESS_MISSING_END_CONTOUR       equ 100154
 GLU_TESS_COORD_TOO_LARGE           equ 100155
 GLU_TESS_NEED_COMBINE_CALLBACK     equ 100156

; TessWinding 
 GLU_TESS_WINDING_ODD               equ 100130
 GLU_TESS_WINDING_NONZERO           equ 100131
 GLU_TESS_WINDING_POSITIVE          equ 100132
 GLU_TESS_WINDING_NEGATIVE          equ 100133
 GLU_TESS_WINDING_ABS_GEQ_TWO       equ 100134

;прототипы функций glu32.dll
extern _gluUnProject@48
extern _gluTessVertex@12
extern _gluTessProperty@16
extern _gluTessNormal@28
extern _gluTessEndPolygon@4
extern _gluTessEndContour@4
extern _gluTessCallback@12
extern _gluTessBeginPolygon@8
extern _gluTessBeginContour@4
extern _gluSphere@20
extern _gluScaleImage@36
extern _gluQuadricTexture@8
extern _gluQuadricOrientation@8
extern _gluQuadricNormals@8
extern _gluQuadricDrawStyle@8
extern _gluQuadricCallback@12
extern _gluPwlCurve@20
extern _gluProject@48
extern _gluPickMatrix@36
extern _gluPerspective@32
extern _gluPartialDisk@44
extern _gluOrtho2D@32
extern _gluNurbsSurface@44
extern _gluNurbsProperty@12
extern _gluNurbsCurve@28
extern _gluNurbsCallback@12
extern _gluNextContour@8
extern _gluNewTess@0
extern _gluNewQuadric@0
extern _gluNewNurbsRenderer@0
extern _gluLookAt@72
extern _gluLoadSamplingMatrices@16
extern _gluGetTessProperty@12
extern _gluGetString@4
extern _gluGetNurbsProperty@12
extern _gluErrorUnicodeStringEXT@4
extern _gluErrorString@4
extern _gluEndTrim@4
extern _gluEndSurface@4
extern _gluEndPolygon@4
extern _gluEndCurve@4
extern _gluDisk@28
extern _gluDeleteTess@4
extern _gluDeleteQuadric@4
extern _gluDeleteNurbsRenderer@4
extern _gluCylinder@36
extern _gluBuild2DMipmaps@28
extern _gluBuild1DMipmaps@24
extern _gluBeginTrim@4
extern _gluBeginSurface@4
extern _gluBeginPolygon@4
extern _gluBeginCurve@4

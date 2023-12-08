;************************************************************************
;*
;* Constants
;*
;************************************************************************

; Boolean values 
 GL_FALSE                                equ 0x0
 GL_TRUE                                 equ 0x1

; Data types 
 GL_BYTE                                 equ 0x1400
 GL_UNSIGNED_BYTE                        equ 0x1401
 GL_SHORT                                equ 0x1402
 GL_UNSIGNED_SHORT                       equ 0x1403
 GL_INT                                  equ 0x1404
 GL_UNSIGNED_INT                         equ 0x1405
 GL_FLOAT                                equ 0x1406
 GL_DOUBLE                               equ 0x140A
 GL_2_BYTES                              equ 0x1407
 GL_3_BYTES                              equ 0x1408
 GL_4_BYTES                              equ 0x1409

; Primitives 
 GL_POINTS                               equ 0x0000
 GL_LINES                                equ 0x0001
 GL_LINE_LOOP                            equ 0x0002
 GL_LINE_STRIP                           equ 0x0003
 GL_TRIANGLES                            equ 0x0004
 GL_TRIANGLE_STRIP                       equ 0x0005
 GL_TRIANGLE_FAN                         equ 0x0006
 GL_QUADS                                equ 0x0007
 GL_QUAD_STRIP                           equ 0x0008
 GL_POLYGON                              equ 0x0009

; Vertex Arrays 
 GL_VERTEX_ARRAY                         equ 0x8074
 GL_NORMAL_ARRAY                         equ 0x8075
 GL_COLOR_ARRAY                          equ 0x8076
 GL_INDEX_ARRAY                          equ 0x8077
 GL_TEXTURE_COORD_ARRAY                  equ 0x8078
 GL_EDGE_FLAG_ARRAY                      equ 0x8079
 GL_VERTEX_ARRAY_SIZE                    equ 0x807A
 GL_VERTEX_ARRAY_TYPE                    equ 0x807B
 GL_VERTEX_ARRAY_STRIDE                  equ 0x807C
 GL_NORMAL_ARRAY_TYPE                    equ 0x807E
 GL_NORMAL_ARRAY_STRIDE                  equ 0x807F
 GL_COLOR_ARRAY_SIZE                     equ 0x8081
 GL_COLOR_ARRAY_TYPE                     equ 0x8082
 GL_COLOR_ARRAY_STRIDE                   equ 0x8083
 GL_INDEX_ARRAY_TYPE                     equ 0x8085
 GL_INDEX_ARRAY_STRIDE                   equ 0x8086
 GL_TEXTURE_COORD_ARRAY_SIZE             equ 0x8088
 GL_TEXTURE_COORD_ARRAY_TYPE             equ 0x8089
 GL_TEXTURE_COORD_ARRAY_STRIDE           equ 0x808A
 GL_EDGE_FLAG_ARRAY_STRIDE               equ 0x808C
 GL_VERTEX_ARRAY_POINTER                 equ 0x808E
 GL_NORMAL_ARRAY_POINTER                 equ 0x808F
 GL_COLOR_ARRAY_POINTER                  equ 0x8090
 GL_INDEX_ARRAY_POINTER                  equ 0x8091
 GL_TEXTURE_COORD_ARRAY_POINTER          equ 0x8092
 GL_EDGE_FLAG_ARRAY_POINTER              equ 0x8093
 GL_V2F                                  equ 0x2A20
 GL_V3F                                  equ 0x2A21
 GL_C4UB_V2F                             equ 0x2A22
 GL_C4UB_V3F                             equ 0x2A23
 GL_C3F_V3F                              equ 0x2A24
 GL_N3F_V3F                              equ 0x2A25
 GL_C4F_N3F_V3F                          equ 0x2A26
 GL_T2F_V3F                              equ 0x2A27
 GL_T4F_V4F                              equ 0x2A28
 GL_T2F_C4UB_V3F                         equ 0x2A29
 GL_T2F_C3F_V3F                          equ 0x2A2A
 GL_T2F_N3F_V3F                          equ 0x2A2B
 GL_T2F_C4F_N3F_V3F                      equ 0x2A2C
 GL_T4F_C4F_N3F_V4F                      equ 0x2A2D

; Matrix Mode 
 GL_MATRIX_MODE                          equ 0x0BA0
 GL_MODELVIEW                            equ 0x1700
 GL_PROJECTION                           equ 0x1701
 GL_TEXTURE                              equ 0x1702

; Points 
 GL_POINT_SMOOTH                         equ 0x0B10
 GL_POINT_SIZE                           equ 0x0B11
 GL_POINT_SIZE_GRANULARITY               equ 0x0B13
 GL_POINT_SIZE_RANGE                     equ 0x0B12

; Lines 
 GL_LINE_SMOOTH                          equ 0x0B20
 GL_LINE_STIPPLE                         equ 0x0B24
 GL_LINE_STIPPLE_PATTERN                 equ 0x0B25
 GL_LINE_STIPPLE_REPEAT                  equ 0x0B26
 GL_LINE_WIDTH                           equ 0x0B21
 GL_LINE_WIDTH_GRANULARITY               equ 0x0B23
 GL_LINE_WIDTH_RANGE                     equ 0x0B22

; Polygons 
 GL_POINT                                equ 0x1B00
 GL_LINE                                 equ 0x1B01
 GL_FILL                                 equ 0x1B02
 GL_CW                                   equ 0x0900
 GL_CCW                                  equ 0x0901
 GL_FRONT                                equ 0x0404
 GL_BACK                                 equ 0x0405
 GL_POLYGON_MODE                         equ 0x0B40
 GL_POLYGON_SMOOTH                       equ 0x0B41
 GL_POLYGON_STIPPLE                      equ 0x0B42
 GL_EDGE_FLAG                            equ 0x0B43
 GL_CULL_FACE                            equ 0x0B44
 GL_CULL_FACE_MODE                       equ 0x0B45
 GL_FRONT_FACE                           equ 0x0B46
 GL_POLYGON_OFFSET_FACTOR                equ 0x8038
 GL_POLYGON_OFFSET_UNITS                 equ 0x2A00
 GL_POLYGON_OFFSET_POINT                 equ 0x2A01
 GL_POLYGON_OFFSET_LINE                  equ 0x2A02
 GL_POLYGON_OFFSET_FILL                  equ 0x8037

; Display Lists 
 GL_COMPILE                              equ 0x1300
 GL_COMPILE_AND_EXECUTE                  equ 0x1301
 GL_LIST_BASE                            equ 0x0B32
 GL_LIST_INDEX                           equ 0x0B33
 GL_LIST_MODE                            equ 0x0B30

; Depth buffer 
 GL_NEVER                                equ 0x0200
 GL_LESS                                 equ 0x0201
 GL_EQUAL                                equ 0x0202
 GL_LEQUAL                               equ 0x0203
 GL_GREATER                              equ 0x0204
 GL_NOTEQUAL                             equ 0x0205
 GL_GEQUAL                               equ 0x0206
 GL_ALWAYS                               equ 0x0207
 GL_DEPTH_TEST                           equ 0x0B71
 GL_DEPTH_BITS                           equ 0x0D56
 GL_DEPTH_CLEAR_VALUE                    equ 0x0B73
 GL_DEPTH_FUNC                           equ 0x0B74
 GL_DEPTH_RANGE                          equ 0x0B70
 GL_DEPTH_WRITEMASK                      equ 0x0B72
 GL_DEPTH_COMPONENT                      equ 0x1902

; Lighting 
 GL_LIGHTING                             equ 0x0B50
 GL_LIGHT0                               equ 0x4000
 GL_LIGHT1                               equ 0x4001
 GL_LIGHT2                               equ 0x4002
 GL_LIGHT3                               equ 0x4003
 GL_LIGHT4                               equ 0x4004
 GL_LIGHT5                               equ 0x4005
 GL_LIGHT6                               equ 0x4006
 GL_LIGHT7                               equ 0x4007
 GL_SPOT_EXPONENT                        equ 0x1205
 GL_SPOT_CUTOFF                          equ 0x1206
 GL_CONSTANT_ATTENUATION                 equ 0x1207
 GL_LINEAR_ATTENUATION                   equ 0x1208
 GL_QUADRATIC_ATTENUATION                equ 0x1209
 GL_AMBIENT                              equ 0x1200
 GL_DIFFUSE                              equ 0x1201
 GL_SPECULAR                             equ 0x1202
 GL_SHININESS                            equ 0x1601
 GL_EMISSION                             equ 0x1600
 GL_POSITION                             equ 0x1203
 GL_SPOT_DIRECTION                       equ 0x1204
 GL_AMBIENT_AND_DIFFUSE                  equ 0x1602
 GL_COLOR_INDEXES                        equ 0x1603
 GL_LIGHT_MODEL_TWO_SIDE                 equ 0x0B52
 GL_LIGHT_MODEL_LOCAL_VIEWER             equ 0x0B51
 GL_LIGHT_MODEL_AMBIENT                  equ 0x0B53
 GL_FRONT_AND_BACK                       equ 0x0408
 GL_SHADE_MODEL                          equ 0x0B54
 GL_FLAT                                 equ 0x1D00
 GL_SMOOTH                               equ 0x1D01
 GL_COLOR_MATERIAL                       equ 0x0B57
 GL_COLOR_MATERIAL_FACE                  equ 0x0B55
 GL_COLOR_MATERIAL_PARAMETER             equ 0x0B56
 GL_NORMALIZE                            equ 0x0BA1

; User clipping planes 
 GL_CLIP_PLANE0                          equ 0x3000
 GL_CLIP_PLANE1                          equ 0x3001
 GL_CLIP_PLANE2                          equ 0x3002
 GL_CLIP_PLANE3                          equ 0x3003
 GL_CLIP_PLANE4                          equ 0x3004
 GL_CLIP_PLANE5                          equ 0x3005

; Accumulation buffer 
 GL_ACCUM_RED_BITS                       equ 0x0D58
 GL_ACCUM_GREEN_BITS                     equ 0x0D59
 GL_ACCUM_BLUE_BITS                      equ 0x0D5A
 GL_ACCUM_ALPHA_BITS                     equ 0x0D5B
 GL_ACCUM_CLEAR_VALUE                    equ 0x0B80
 GL_ACCUM                                equ 0x0100
 GL_ADD                                  equ 0x0104
 GL_LOAD                                 equ 0x0101
 GL_MULT                                 equ 0x0103
 GL_RETURN                               equ 0x0102

; Alpha testing 
 GL_ALPHA_TEST                           equ 0x0BC0
 GL_ALPHA_TEST_REF                       equ 0x0BC2
 GL_ALPHA_TEST_FUNC                      equ 0x0BC1

; Blending 
 GL_BLEND                                equ 0x0BE2
 GL_BLEND_SRC                            equ 0x0BE1
 GL_BLEND_DST                            equ 0x0BE0
 GL_ZERO                                 equ 0x0
 GL_ONE                                  equ 0x1
 GL_SRC_COLOR                            equ 0x0300
 GL_ONE_MINUS_SRC_COLOR                  equ 0x0301
 GL_SRC_ALPHA                            equ 0x0302
 GL_ONE_MINUS_SRC_ALPHA                  equ 0x0303
 GL_DST_ALPHA                            equ 0x0304
 GL_ONE_MINUS_DST_ALPHA                  equ 0x0305
 GL_DST_COLOR                            equ 0x0306
 GL_ONE_MINUS_DST_COLOR                  equ 0x0307
 GL_SRC_ALPHA_SATURATE                   equ 0x0308
 GL_CONSTANT_COLOR                       equ 0x8001
 GL_ONE_MINUS_CONSTANT_COLOR             equ 0x8002
 GL_CONSTANT_ALPHA                       equ 0x8003
 GL_ONE_MINUS_CONSTANT_ALPHA             equ 0x8004

; Render Mode 
 GL_FEEDBACK                             equ 0x1C01
 GL_RENDER                               equ 0x1C00
 GL_SELECT                               equ 0x1C02

; Feedback 
 GL_2D                                   equ 0x0600
 GL_3D                                   equ 0x0601
 GL_3D_COLOR                             equ 0x0602
 GL_3D_COLOR_TEXTURE                     equ 0x0603
 GL_4D_COLOR_TEXTURE                     equ 0x0604
 GL_POINT_TOKEN                          equ 0x0701
 GL_LINE_TOKEN                           equ 0x0702
 GL_LINE_RESET_TOKEN                     equ 0x0707
 GL_POLYGON_TOKEN                        equ 0x0703
 GL_BITMAP_TOKEN                         equ 0x0704
 GL_DRAW_PIXEL_TOKEN                     equ 0x0705
 GL_COPY_PIXEL_TOKEN                     equ 0x0706
 GL_PASS_THROUGH_TOKEN                   equ 0x0700
 GL_FEEDBACK_BUFFER_POINTER              equ 0x0DF0
 GL_FEEDBACK_BUFFER_SIZE                 equ 0x0DF1
 GL_FEEDBACK_BUFFER_TYPE                 equ 0x0DF2

; Selection 
 GL_SELECTION_BUFFER_POINTER             equ 0x0DF3
 GL_SELECTION_BUFFER_SIZE                equ 0x0DF4

; Fog 
 GL_FOG                                  equ 0x0B60
 GL_FOG_MODE                             equ 0x0B65
 GL_FOG_DENSITY                          equ 0x0B62
 GL_FOG_COLOR                            equ 0x0B66
 GL_FOG_INDEX                            equ 0x0B61
 GL_FOG_START                            equ 0x0B63
 GL_FOG_END                              equ 0x0B64
 GL_LINEAR                               equ 0x2601
 GL_EXP                                  equ 0x0800
 GL_EXP2                                 equ 0x0801

; Logic Ops 
 GL_LOGIC_OP                             equ 0x0BF1
 GL_INDEX_LOGIC_OP                       equ 0x0BF1
 GL_COLOR_LOGIC_OP                       equ 0x0BF2
 GL_LOGIC_OP_MODE                        equ 0x0BF0
 GL_CLEAR                                equ 0x1500
 GL_SET                                  equ 0x150F
 GL_COPY                                 equ 0x1503
 GL_COPY_INVERTED                        equ 0x150C
 GL_NOOP                                 equ 0x1505
 GL_INVERT                               equ 0x150A
 GL_AND                                  equ 0x1501
 GL_NAND                                 equ 0x150E
 GL_OR                                   equ 0x1507
 GL_NOR                                  equ 0x1508
 GL_XOR                                  equ 0x1506
 GL_EQUIV                                equ 0x1509
 GL_AND_REVERSE                          equ 0x1502
 GL_AND_INVERTED                         equ 0x1504
 GL_OR_REVERSE                           equ 0x150B
 GL_OR_INVERTED                          equ 0x150D

; Stencil 
 GL_STENCIL_TEST                         equ 0x0B90
 GL_STENCIL_WRITEMASK                    equ 0x0B98
 GL_STENCIL_BITS                         equ 0x0D57
 GL_STENCIL_FUNC                         equ 0x0B92
 GL_STENCIL_VALUE_MASK                   equ 0x0B93
 GL_STENCIL_REF                          equ 0x0B97
 GL_STENCIL_FAIL                         equ 0x0B94
 GL_STENCIL_PASS_DEPTH_PASS              equ 0x0B96
 GL_STENCIL_PASS_DEPTH_FAIL              equ 0x0B95
 GL_STENCIL_CLEAR_VALUE                  equ 0x0B91
 GL_STENCIL_INDEX                        equ 0x1901
 GL_KEEP                                 equ 0x1E00
 GL_REPLACE                              equ 0x1E01
 GL_INCR                                 equ 0x1E02
 GL_DECR                                 equ 0x1E03

; Buffers, Pixel Drawing/Reading 
 GL_NONE                                 equ 0x0
 GL_LEFT                                 equ 0x0406
 GL_RIGHT                                equ 0x0407
;GL_FRONT                                      equ 0x0404 
;GL_BACK                                       equ 0x0405 
;GL_FRONT_AND_BACK                             equ 0x0408 
 GL_FRONT_LEFT                           equ 0x0400
 GL_FRONT_RIGHT                          equ 0x0401
 GL_BACK_LEFT                            equ 0x0402
 GL_BACK_RIGHT                           equ 0x0403
 GL_AUX0                                 equ 0x0409
 GL_AUX1                                 equ 0x040A
 GL_AUX2                                 equ 0x040B
 GL_AUX3                                 equ 0x040C
 GL_COLOR_INDEX                          equ 0x1900
 GL_RED                                  equ 0x1903
 GL_GREEN                                equ 0x1904
 GL_BLUE                                 equ 0x1905
 GL_ALPHA                                equ 0x1906
 GL_LUMINANCE                            equ 0x1909
 GL_LUMINANCE_ALPHA                      equ 0x190A
 GL_ALPHA_BITS                           equ 0x0D55
 GL_RED_BITS                             equ 0x0D52
 GL_GREEN_BITS                           equ 0x0D53
 GL_BLUE_BITS                            equ 0x0D54
 GL_INDEX_BITS                           equ 0x0D51
 GL_SUBPIXEL_BITS                        equ 0x0D50
 GL_AUX_BUFFERS                          equ 0x0C00
 GL_READ_BUFFER                          equ 0x0C02
 GL_DRAW_BUFFER                          equ 0x0C01
 GL_DOUBLEBUFFER                         equ 0x0C32
 GL_STEREO                               equ 0x0C33
 GL_BITMAP                               equ 0x1A00
 GL_COLOR                                equ 0x1800
 GL_DEPTH                                equ 0x1801
 GL_STENCIL                              equ 0x1802
 GL_DITHER                               equ 0x0BD0
 GL_RGB                                  equ 0x1907
 GL_RGBA                                 equ 0x1908

; Implementation limits 
 GL_MAX_LIST_NESTING                     equ 0x0B31
 GL_MAX_ATTRIB_STACK_DEPTH               equ 0x0D35
 GL_MAX_MODELVIEW_STACK_DEPTH            equ 0x0D36
 GL_MAX_NAME_STACK_DEPTH                 equ 0x0D37
 GL_MAX_PROJECTION_STACK_DEPTH           equ 0x0D38
 GL_MAX_TEXTURE_STACK_DEPTH              equ 0x0D39
 GL_MAX_EVAL_ORDER                       equ 0x0D30
 GL_MAX_LIGHTS                           equ 0x0D31
 GL_MAX_CLIP_PLANES                      equ 0x0D32
 GL_MAX_TEXTURE_SIZE                     equ 0x0D33
 GL_MAX_PIXEL_MAP_TABLE                  equ 0x0D34
 GL_MAX_VIEWPORT_DIMS                    equ 0x0D3A
 GL_MAX_CLIENT_ATTRIB_STACK_DEPTH        equ 0x0D3B

; Gets 
 GL_ATTRIB_STACK_DEPTH                   equ 0x0BB0
 GL_CLIENT_ATTRIB_STACK_DEPTH            equ 0x0BB1
 GL_COLOR_CLEAR_VALUE                    equ 0x0C22
 GL_COLOR_WRITEMASK                      equ 0x0C23
 GL_CURRENT_INDEX                        equ 0x0B01
 GL_CURRENT_COLOR                        equ 0x0B00
 GL_CURRENT_NORMAL                       equ 0x0B02
 GL_CURRENT_RASTER_COLOR                 equ 0x0B04
 GL_CURRENT_RASTER_DISTANCE              equ 0x0B09
 GL_CURRENT_RASTER_INDEX                 equ 0x0B05
 GL_CURRENT_RASTER_POSITION              equ 0x0B07
 GL_CURRENT_RASTER_TEXTURE_COORDS        equ 0x0B06
 GL_CURRENT_RASTER_POSITION_VALID        equ 0x0B08
 GL_CURRENT_TEXTURE_COORDS               equ 0x0B03
 GL_INDEX_CLEAR_VALUE                    equ 0x0C20
 GL_INDEX_MODE                           equ 0x0C30
 GL_INDEX_WRITEMASK                      equ 0x0C21
 GL_MODELVIEW_MATRIX                     equ 0x0BA6
 GL_MODELVIEW_STACK_DEPTH                equ 0x0BA3
 GL_NAME_STACK_DEPTH                     equ 0x0D70
 GL_PROJECTION_MATRIX                    equ 0x0BA7
 GL_PROJECTION_STACK_DEPTH               equ 0x0BA4
 GL_RENDER_MODE                          equ 0x0C40
 GL_RGBA_MODE                            equ 0x0C31
 GL_TEXTURE_MATRIX                       equ 0x0BA8
 GL_TEXTURE_STACK_DEPTH                  equ 0x0BA5
 GL_VIEWPORT                             equ 0x0BA2

; Evaluators 
 GL_AUTO_NORMAL                          equ 0x0D80
 GL_MAP1_COLOR_4                         equ 0x0D90
 GL_MAP1_GRID_DOMAIN                     equ 0x0DD0
 GL_MAP1_GRID_SEGMENTS                   equ 0x0DD1
 GL_MAP1_INDEX                           equ 0x0D91
 GL_MAP1_NORMAL                          equ 0x0D92
 GL_MAP1_TEXTURE_COORD_1                 equ 0x0D93
 GL_MAP1_TEXTURE_COORD_2                 equ 0x0D94
 GL_MAP1_TEXTURE_COORD_3                 equ 0x0D95
 GL_MAP1_TEXTURE_COORD_4                 equ 0x0D96
 GL_MAP1_VERTEX_3                        equ 0x0D97
 GL_MAP1_VERTEX_4                        equ 0x0D98
 GL_MAP2_COLOR_4                         equ 0x0DB0
 GL_MAP2_GRID_DOMAIN                     equ 0x0DD2
 GL_MAP2_GRID_SEGMENTS                   equ 0x0DD3
 GL_MAP2_INDEX                           equ 0x0DB1
 GL_MAP2_NORMAL                          equ 0x0DB2
 GL_MAP2_TEXTURE_COORD_1                 equ 0x0DB3
 GL_MAP2_TEXTURE_COORD_2                 equ 0x0DB4
 GL_MAP2_TEXTURE_COORD_3                 equ 0x0DB5
 GL_MAP2_TEXTURE_COORD_4                 equ 0x0DB6
 GL_MAP2_VERTEX_3                        equ 0x0DB7
 GL_MAP2_VERTEX_4                        equ 0x0DB8
 GL_COEFF                                equ 0x0A00
 GL_DOMAIN                               equ 0x0A02
 GL_ORDER                                equ 0x0A01

; Hints 
 GL_FOG_HINT                             equ 0x0C54
 GL_LINE_SMOOTH_HINT                     equ 0x0C52
 GL_PERSPECTIVE_CORRECTION_HINT          equ 0x0C50
 GL_POINT_SMOOTH_HINT                    equ 0x0C51
 GL_POLYGON_SMOOTH_HINT                  equ 0x0C53
 GL_DONT_CARE                            equ 0x1100
 GL_FASTEST                              equ 0x1101
 GL_NICEST                               equ 0x1102

; Scissor box 
 GL_SCISSOR_TEST                         equ 0x0C11
 GL_SCISSOR_BOX                          equ 0x0C10

; Pixel Mode / Transfer 
 GL_MAP_COLOR                            equ 0x0D10
 GL_MAP_STENCIL                          equ 0x0D11
 GL_INDEX_SHIFT                          equ 0x0D12
 GL_INDEX_OFFSET                         equ 0x0D13
 GL_RED_SCALE                            equ 0x0D14
 GL_RED_BIAS                             equ 0x0D15
 GL_GREEN_SCALE                          equ 0x0D18
 GL_GREEN_BIAS                           equ 0x0D19
 GL_BLUE_SCALE                           equ 0x0D1A
 GL_BLUE_BIAS                            equ 0x0D1B
 GL_ALPHA_SCALE                          equ 0x0D1C
 GL_ALPHA_BIAS                           equ 0x0D1D
 GL_DEPTH_SCALE                          equ 0x0D1E
 GL_DEPTH_BIAS                           equ 0x0D1F
 GL_PIXEL_MAP_S_TO_S_SIZE                equ 0x0CB1
 GL_PIXEL_MAP_I_TO_I_SIZE                equ 0x0CB0
 GL_PIXEL_MAP_I_TO_R_SIZE                equ 0x0CB2
 GL_PIXEL_MAP_I_TO_G_SIZE                equ 0x0CB3
 GL_PIXEL_MAP_I_TO_B_SIZE                equ 0x0CB4
 GL_PIXEL_MAP_I_TO_A_SIZE                equ 0x0CB5
 GL_PIXEL_MAP_R_TO_R_SIZE                equ 0x0CB6
 GL_PIXEL_MAP_G_TO_G_SIZE                equ 0x0CB7
 GL_PIXEL_MAP_B_TO_B_SIZE                equ 0x0CB8
 GL_PIXEL_MAP_A_TO_A_SIZE                equ 0x0CB9
 GL_PIXEL_MAP_S_TO_S                     equ 0x0C71
 GL_PIXEL_MAP_I_TO_I                     equ 0x0C70
 GL_PIXEL_MAP_I_TO_R                     equ 0x0C72
 GL_PIXEL_MAP_I_TO_G                     equ 0x0C73
 GL_PIXEL_MAP_I_TO_B                     equ 0x0C74
 GL_PIXEL_MAP_I_TO_A                     equ 0x0C75
 GL_PIXEL_MAP_R_TO_R                     equ 0x0C76
 GL_PIXEL_MAP_G_TO_G                     equ 0x0C77
 GL_PIXEL_MAP_B_TO_B                     equ 0x0C78
 GL_PIXEL_MAP_A_TO_A                     equ 0x0C79
 GL_PACK_ALIGNMENT                       equ 0x0D05
 GL_PACK_LSB_FIRST                       equ 0x0D01
 GL_PACK_ROW_LENGTH                      equ 0x0D02
 GL_PACK_SKIP_PIXELS                     equ 0x0D04
 GL_PACK_SKIP_ROWS                       equ 0x0D03
 GL_PACK_SWAP_BYTES                      equ 0x0D00
 GL_UNPACK_ALIGNMENT                     equ 0x0CF5
 GL_UNPACK_LSB_FIRST                     equ 0x0CF1
 GL_UNPACK_ROW_LENGTH                    equ 0x0CF2
 GL_UNPACK_SKIP_PIXELS                   equ 0x0CF4
 GL_UNPACK_SKIP_ROWS                     equ 0x0CF3
 GL_UNPACK_SWAP_BYTES                    equ 0x0CF0
 GL_ZOOM_X                               equ 0x0D16
 GL_ZOOM_Y                               equ 0x0D17

; Texture mapping 
 GL_TEXTURE_ENV                          equ 0x2300
 GL_TEXTURE_ENV_MODE                     equ 0x2200
 GL_TEXTURE_1D                           equ 0x0DE0
 GL_TEXTURE_2D                           equ 0x0DE1
 GL_TEXTURE_WRAP_S                       equ 0x2802
 GL_TEXTURE_WRAP_T                       equ 0x2803
 GL_TEXTURE_MAG_FILTER                   equ 0x2800
 GL_TEXTURE_MIN_FILTER                   equ 0x2801
 GL_TEXTURE_ENV_COLOR                    equ 0x2201
 GL_TEXTURE_GEN_S                        equ 0x0C60
 GL_TEXTURE_GEN_T                        equ 0x0C61
 GL_TEXTURE_GEN_MODE                     equ 0x2500
 GL_TEXTURE_BORDER_COLOR                 equ 0x1004
 GL_TEXTURE_WIDTH                        equ 0x1000
 GL_TEXTURE_HEIGHT                       equ 0x1001
 GL_TEXTURE_BORDER                       equ 0x1005
 GL_TEXTURE_COMPONENTS                   equ 0x1003
 GL_TEXTURE_RED_SIZE                     equ 0x805C
 GL_TEXTURE_GREEN_SIZE                   equ 0x805D
 GL_TEXTURE_BLUE_SIZE                    equ 0x805E
 GL_TEXTURE_ALPHA_SIZE                   equ 0x805F
 GL_TEXTURE_LUMINANCE_SIZE               equ 0x8060
 GL_TEXTURE_INTENSITY_SIZE               equ 0x8061
 GL_NEAREST_MIPMAP_NEAREST               equ 0x2700
 GL_NEAREST_MIPMAP_LINEAR                equ 0x2702
 GL_LINEAR_MIPMAP_NEAREST                equ 0x2701
 GL_LINEAR_MIPMAP_LINEAR                 equ 0x2703
 GL_OBJECT_LINEAR                        equ 0x2401
 GL_OBJECT_PLANE                         equ 0x2501
 GL_EYE_LINEAR                           equ 0x2400
 GL_EYE_PLANE                            equ 0x2502
 GL_SPHERE_MAP                           equ 0x2402
 GL_DECAL                                equ 0x2101
 GL_MODULATE                             equ 0x2100
 GL_NEAREST                              equ 0x2600
 GL_REPEAT                               equ 0x2901
 GL_CLAMP                                equ 0x2900
 GL_S                                    equ 0x2000
 GL_T                                    equ 0x2001
 GL_R                                    equ 0x2002
 GL_Q                                    equ 0x2003
 GL_TEXTURE_GEN_R                        equ 0x0C62
 GL_TEXTURE_GEN_Q                        equ 0x0C63

; Utility 
 GL_VENDOR                               equ 0x1F00
 GL_RENDERER                             equ 0x1F01
 GL_VERSION                              equ 0x1F02
 GL_EXTENSIONS                           equ 0x1F03

; Errors 
 GL_NO_ERROR                             equ 0x0
 GL_INVALID_VALUE                        equ 0x0501
 GL_INVALID_ENUM                         equ 0x0500
 GL_INVALID_OPERATION                    equ 0x0502
 GL_STACK_OVERFLOW                       equ 0x0503
 GL_STACK_UNDERFLOW                      equ 0x0504
 GL_OUT_OF_MEMORY                        equ 0x0505

; glPush/PopAttrib bits 
 GL_CURRENT_BIT                          equ 0x00000001
 GL_POINT_BIT                            equ 0x00000002
 GL_LINE_BIT                             equ 0x00000004
 GL_POLYGON_BIT                          equ 0x00000008
 GL_POLYGON_STIPPLE_BIT                  equ 0x00000010
 GL_PIXEL_MODE_BIT                       equ 0x00000020
 GL_LIGHTING_BIT                         equ 0x00000040
 GL_FOG_BIT                              equ 0x00000080
 GL_DEPTH_BUFFER_BIT                     equ 0x00000100
 GL_ACCUM_BUFFER_BIT                     equ 0x00000200
 GL_STENCIL_BUFFER_BIT                   equ 0x00000400
 GL_VIEWPORT_BIT                         equ 0x00000800
 GL_TRANSFORM_BIT                        equ 0x00001000
 GL_ENABLE_BIT                           equ 0x00002000
 GL_COLOR_BUFFER_BIT                     equ 0x00004000
 GL_HINT_BIT                             equ 0x00008000
 GL_EVAL_BIT                             equ 0x00010000
 GL_LIST_BIT                             equ 0x00020000
 GL_TEXTURE_BIT                          equ 0x00040000
 GL_SCISSOR_BIT                          equ 0x00080000
 GL_ALL_ATTRIB_BITS                      equ 0x000FFFFF


; OpenGL 1.1 
 GL_PROXY_TEXTURE_1D                     equ 0x8063
 GL_PROXY_TEXTURE_2D                     equ 0x8064
 GL_TEXTURE_PRIORITY                     equ 0x8066
 GL_TEXTURE_RESIDENT                     equ 0x8067
 GL_TEXTURE_BINDING_1D                   equ 0x8068
 GL_TEXTURE_BINDING_2D                   equ 0x8069
 GL_TEXTURE_INTERNAL_FORMAT              equ 0x1003
 GL_ALPHA4                               equ 0x803B
 GL_ALPHA8                               equ 0x803C
 GL_ALPHA12                              equ 0x803D
 GL_ALPHA16                              equ 0x803E
 GL_LUMINANCE4                           equ 0x803F
 GL_LUMINANCE8                           equ 0x8040
 GL_LUMINANCE12                          equ 0x8041
 GL_LUMINANCE16                          equ 0x8042
 GL_LUMINANCE4_ALPHA4                    equ 0x8043
 GL_LUMINANCE6_ALPHA2                    equ 0x8044
 GL_LUMINANCE8_ALPHA8                    equ 0x8045
 GL_LUMINANCE12_ALPHA4                   equ 0x8046
 GL_LUMINANCE12_ALPHA12                  equ 0x8047
 GL_LUMINANCE16_ALPHA16                  equ 0x8048
 GL_INTENSITY                            equ 0x8049
 GL_INTENSITY4                           equ 0x804A
 GL_INTENSITY8                           equ 0x804B
 GL_INTENSITY12                          equ 0x804C
 GL_INTENSITY16                          equ 0x804D
 GL_R3_G3_B2                             equ 0x2A10
 GL_RGB4                                 equ 0x804F
 GL_RGB5                                 equ 0x8050
 GL_RGB8                                 equ 0x8051
 GL_RGB10                                equ 0x8052
 GL_RGB12                                equ 0x8053
 GL_RGB16                                equ 0x8054
 GL_RGBA2                                equ 0x8055
 GL_RGBA4                                equ 0x8056
 GL_RGB5_A1                              equ 0x8057
 GL_RGBA8                                equ 0x8058
 GL_RGB10_A2                             equ 0x8059
 GL_RGBA12                               equ 0x805A
 GL_RGBA16                               equ 0x805B
 GL_CLIENT_PIXEL_STORE_BIT               equ 0x00000001
 GL_CLIENT_VERTEX_ARRAY_BIT              equ 0x00000002
 GL_ALL_CLIENT_ATTRIB_BITS               equ 0xFFFFFFFF
 GL_CLIENT_ALL_ATTRIB_BITS               equ 0xFFFFFFFF

; OpenGL 1.2 
 GL_RESCALE_NORMAL                       equ 0x803A
 GL_CLAMP_TO_EDGE                        equ 0x812F
 GL_MAX_ELEMENTS_VERTICES                equ 0x80E8
 GL_MAX_ELEMENTS_INDICES                 equ 0x80E9
 GL_BGR                                  equ 0x80E0
 GL_BGRA                                 equ 0x80E1
 GL_UNSIGNED_BYTE_3_3_2                  equ 0x8032
 GL_UNSIGNED_BYTE_2_3_3_REV              equ 0x8362
 GL_UNSIGNED_SHORT_5_6_5                 equ 0x8363
 GL_UNSIGNED_SHORT_5_6_5_REV             equ 0x8364
 GL_UNSIGNED_SHORT_4_4_4_4               equ 0x8033
 GL_UNSIGNED_SHORT_4_4_4_4_REV           equ 0x8365
 GL_UNSIGNED_SHORT_5_5_5_1               equ 0x8034
 GL_UNSIGNED_SHORT_1_5_5_5_REV           equ 0x8366
 GL_UNSIGNED_INT_8_8_8_8                 equ 0x8035
 GL_UNSIGNED_INT_8_8_8_8_REV             equ 0x8367
 GL_UNSIGNED_INT_10_10_10_2              equ 0x8036
 GL_UNSIGNED_INT_2_10_10_10_REV          equ 0x8368
 GL_LIGHT_MODEL_COLOR_CONTROL            equ 0x81F8
 GL_SINGLE_COLOR                         equ 0x81F9
 GL_SEPARATE_SPECULAR_COLOR              equ 0x81FA
 GL_TEXTURE_MIN_LOD                      equ 0x813A
 GL_TEXTURE_MAX_LOD                      equ 0x813B
 GL_TEXTURE_BASE_LEVEL                   equ 0x813C
 GL_TEXTURE_MAX_LEVEL                    equ 0x813D
 GL_SMOOTH_POINT_SIZE_RANGE              equ 0x0B12
 GL_SMOOTH_POINT_SIZE_GRANULARITY        equ 0x0B13
 GL_SMOOTH_LINE_WIDTH_RANGE              equ 0x0B22
 GL_SMOOTH_LINE_WIDTH_GRANULARITY        equ 0x0B23
 GL_ALIASED_POINT_SIZE_RANGE             equ 0x846D
 GL_ALIASED_LINE_WIDTH_RANGE             equ 0x846E
 GL_PACK_SKIP_IMAGES                     equ 0x806B
 GL_PACK_IMAGE_HEIGHT                    equ 0x806C
 GL_UNPACK_SKIP_IMAGES                   equ 0x806D
 GL_UNPACK_IMAGE_HEIGHT                  equ 0x806E
 GL_TEXTURE_3D                           equ 0x806F
 GL_PROXY_TEXTURE_3D                     equ 0x8070
 GL_TEXTURE_DEPTH                        equ 0x8071
 GL_TEXTURE_WRAP_R                       equ 0x8072
 GL_MAX_3D_TEXTURE_SIZE                  equ 0x8073
 GL_TEXTURE_BINDING_3D                   equ 0x806A

; OpenGL 1.2 imaging subset 
; GL_EXT_color_table 
 GL_COLOR_TABLE                          equ 0x80D0
 GL_POST_CONVOLUTION_COLOR_TABLE         equ 0x80D1
 GL_POST_COLOR_MATRIX_COLOR_TABLE        equ 0x80D2
 GL_PROXY_COLOR_TABLE                    equ 0x80D3
 GL_PROXY_POST_CONVOLUTION_COLOR_TABLE   equ 0x80D4
 GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE  equ 0x80D5
 GL_COLOR_TABLE_SCALE                    equ 0x80D6
 GL_COLOR_TABLE_BIAS                     equ 0x80D7
 GL_COLOR_TABLE_FORMAT                   equ 0x80D8
 GL_COLOR_TABLE_WIDTH                    equ 0x80D9
 GL_COLOR_TABLE_RED_SIZE                 equ 0x80DA
 GL_COLOR_TABLE_GREEN_SIZE               equ 0x80DB
 GL_COLOR_TABLE_BLUE_SIZE                equ 0x80DC
 GL_COLOR_TABLE_ALPHA_SIZE               equ 0x80DD
 GL_COLOR_TABLE_LUMINANCE_SIZE           equ 0x80DE
 GL_COLOR_TABLE_INTENSITY_SIZE           equ 0x80DF
; GL_EXT_convolution and GL_HP_convolution_border_modes 
 GL_CONVOLUTION_1D                       equ 0x8010
 GL_CONVOLUTION_2D                       equ 0x8011
 GL_SEPARABLE_2D                         equ 0x8012
 GL_CONVOLUTION_BORDER_MODE              equ 0x8013
 GL_CONVOLUTION_FILTER_SCALE             equ 0x8014
 GL_CONVOLUTION_FILTER_BIAS              equ 0x8015
 GL_REDUCE                               equ 0x8016
 GL_CONVOLUTION_FORMAT                   equ 0x8017
 GL_CONVOLUTION_WIDTH                    equ 0x8018
 GL_CONVOLUTION_HEIGHT                   equ 0x8019
 GL_MAX_CONVOLUTION_WIDTH                equ 0x801A
 GL_MAX_CONVOLUTION_HEIGHT               equ 0x801B
 GL_POST_CONVOLUTION_RED_SCALE           equ 0x801C
 GL_POST_CONVOLUTION_GREEN_SCALE         equ 0x801D
 GL_POST_CONVOLUTION_BLUE_SCALE          equ 0x801E
 GL_POST_CONVOLUTION_ALPHA_SCALE         equ 0x801F
 GL_POST_CONVOLUTION_RED_BIAS            equ 0x8020
 GL_POST_CONVOLUTION_GREEN_BIAS          equ 0x8021
 GL_POST_CONVOLUTION_BLUE_BIAS           equ 0x8022
 GL_POST_CONVOLUTION_ALPHA_BIAS          equ 0x8023
 GL_CONSTANT_BORDER                      equ 0x8151
 GL_REPLICATE_BORDER                     equ 0x8153
 GL_CONVOLUTION_BORDER_COLOR             equ 0x8154
; GL_SGI_color_matrix 
 GL_COLOR_MATRIX                         equ 0x80B1
 GL_COLOR_MATRIX_STACK_DEPTH             equ 0x80B2
 GL_MAX_COLOR_MATRIX_STACK_DEPTH         equ 0x80B3
 GL_POST_COLOR_MATRIX_RED_SCALE          equ 0x80B4
 GL_POST_COLOR_MATRIX_GREEN_SCALE        equ 0x80B5
 GL_POST_COLOR_MATRIX_BLUE_SCALE         equ 0x80B6
 GL_POST_COLOR_MATRIX_ALPHA_SCALE        equ 0x80B7
 GL_POST_COLOR_MATRIX_RED_BIAS           equ 0x80B8
 GL_POST_COLOR_MATRIX_GREEN_BIAS         equ 0x80B9
 GL_POST_COLOR_MATRIX_BLUE_BIAS          equ 0x80BA
 GL_POST_COLOR_MATRIX_ALPHA_BIAS         equ 0x80BB
; GL_EXT_histogram 
 GL_HISTOGRAM                            equ 0x8024
 GL_PROXY_HISTOGRAM                      equ 0x8025
 GL_HISTOGRAM_WIDTH                      equ 0x8026
 GL_HISTOGRAM_FORMAT                     equ 0x8027
 GL_HISTOGRAM_RED_SIZE                   equ 0x8028
 GL_HISTOGRAM_GREEN_SIZE                 equ 0x8029
 GL_HISTOGRAM_BLUE_SIZE                  equ 0x802A
 GL_HISTOGRAM_ALPHA_SIZE                 equ 0x802B
 GL_HISTOGRAM_LUMINANCE_SIZE             equ 0x802C
 GL_HISTOGRAM_SINK                       equ 0x802D
 GL_MINMAX                               equ 0x802E
 GL_MINMAX_FORMAT                        equ 0x802F
 GL_MINMAX_SINK                          equ 0x8030
 GL_TABLE_TOO_LARGE                      equ 0x8031
; GL_EXT_blend_color, GL_EXT_blend_minmax 
 GL_BLEND_EQUATION                       equ 0x8009
 GL_MIN                                  equ 0x8007
 GL_MAX                                  equ 0x8008
 GL_FUNC_ADD                             equ 0x8006
 GL_FUNC_SUBTRACT                        equ 0x800A
 GL_FUNC_REVERSE_SUBTRACT                equ 0x800B
 GL_BLEND_COLOR                          equ 0x8005


; OpenGL 1.3 
; multitexture 
 GL_TEXTURE0                             equ 0x84C0
 GL_TEXTURE1                             equ 0x84C1
 GL_TEXTURE2                             equ 0x84C2
 GL_TEXTURE3                             equ 0x84C3
 GL_TEXTURE4                             equ 0x84C4
 GL_TEXTURE5                             equ 0x84C5
 GL_TEXTURE6                             equ 0x84C6
 GL_TEXTURE7                             equ 0x84C7
 GL_TEXTURE8                             equ 0x84C8
 GL_TEXTURE9                             equ 0x84C9
 GL_TEXTURE10                            equ 0x84CA
 GL_TEXTURE11                            equ 0x84CB
 GL_TEXTURE12                            equ 0x84CC
 GL_TEXTURE13                            equ 0x84CD
 GL_TEXTURE14                            equ 0x84CE
 GL_TEXTURE15                            equ 0x84CF
 GL_TEXTURE16                            equ 0x84D0
 GL_TEXTURE17                            equ 0x84D1
 GL_TEXTURE18                            equ 0x84D2
 GL_TEXTURE19                            equ 0x84D3
 GL_TEXTURE20                            equ 0x84D4
 GL_TEXTURE21                            equ 0x84D5
 GL_TEXTURE22                            equ 0x84D6
 GL_TEXTURE23                            equ 0x84D7
 GL_TEXTURE24                            equ 0x84D8
 GL_TEXTURE25                            equ 0x84D9
 GL_TEXTURE26                            equ 0x84DA
 GL_TEXTURE27                            equ 0x84DB
 GL_TEXTURE28                            equ 0x84DC
 GL_TEXTURE29                            equ 0x84DD
 GL_TEXTURE30                            equ 0x84DE
 GL_TEXTURE31                            equ 0x84DF
 GL_ACTIVE_TEXTURE                       equ 0x84E0
 GL_CLIENT_ACTIVE_TEXTURE                equ 0x84E1
 GL_MAX_TEXTURE_UNITS                    equ 0x84E2
; texture_cube_map 
 GL_NORMAL_MAP                           equ 0x8511
 GL_REFLECTION_MAP                       equ 0x8512
 GL_TEXTURE_CUBE_MAP                     equ 0x8513
 GL_TEXTURE_BINDING_CUBE_MAP             equ 0x8514
 GL_TEXTURE_CUBE_MAP_POSITIVE_X          equ 0x8515
 GL_TEXTURE_CUBE_MAP_NEGATIVE_X          equ 0x8516
 GL_TEXTURE_CUBE_MAP_POSITIVE_Y          equ 0x8517
 GL_TEXTURE_CUBE_MAP_NEGATIVE_Y          equ 0x8518
 GL_TEXTURE_CUBE_MAP_POSITIVE_Z          equ 0x8519
 GL_TEXTURE_CUBE_MAP_NEGATIVE_Z          equ 0x851A
 GL_PROXY_TEXTURE_CUBE_MAP               equ 0x851B
 GL_MAX_CUBE_MAP_TEXTURE_SIZE            equ 0x851C
; texture_compression 
 GL_COMPRESSED_ALPHA                     equ 0x84E9
 GL_COMPRESSED_LUMINANCE                 equ 0x84EA
 GL_COMPRESSED_LUMINANCE_ALPHA           equ 0x84EB
 GL_COMPRESSED_INTENSITY                 equ 0x84EC
 GL_COMPRESSED_RGB                       equ 0x84ED
 GL_COMPRESSED_RGBA                      equ 0x84EE
 GL_TEXTURE_COMPRESSION_HINT             equ 0x84EF
 GL_TEXTURE_COMPRESSED_IMAGE_SIZE        equ 0x86A0
 GL_TEXTURE_COMPRESSED                   equ 0x86A1
 GL_NUM_COMPRESSED_TEXTURE_FORMATS       equ 0x86A2
 GL_COMPRESSED_TEXTURE_FORMATS           equ 0x86A3
; multisample 
 GL_MULTISAMPLE                          equ 0x809D
 GL_SAMPLE_ALPHA_TO_COVERAGE             equ 0x809E
 GL_SAMPLE_ALPHA_TO_ONE                  equ 0x809F
 GL_SAMPLE_COVERAGE                      equ 0x80A0
 GL_SAMPLE_BUFFERS                       equ 0x80A8
 GL_SAMPLES                              equ 0x80A9
 GL_SAMPLE_COVERAGE_VALUE                equ 0x80AA
 GL_SAMPLE_COVERAGE_INVERT               equ 0x80AB
 GL_MULTISAMPLE_BIT                      equ 0x20000000
; transpose_matrix 
 GL_TRANSPOSE_MODELVIEW_MATRIX           equ 0x84E3
 GL_TRANSPOSE_PROJECTION_MATRIX          equ 0x84E4
 GL_TRANSPOSE_TEXTURE_MATRIX             equ 0x84E5
 GL_TRANSPOSE_COLOR_MATRIX               equ 0x84E6
; texture_env_combine 
 GL_COMBINE                              equ 0x8570
 GL_COMBINE_RGB                          equ 0x8571
 GL_COMBINE_ALPHA                        equ 0x8572
 GL_SOURCE0_RGB                          equ 0x8580
 GL_SOURCE1_RGB                          equ 0x8581
 GL_SOURCE2_RGB                          equ 0x8582
 GL_SOURCE0_ALPHA                        equ 0x8588
 GL_SOURCE1_ALPHA                        equ 0x8589
 GL_SOURCE2_ALPHA                        equ 0x858A
 GL_OPERAND0_RGB                         equ 0x8590
 GL_OPERAND1_RGB                         equ 0x8591
 GL_OPERAND2_RGB                         equ 0x8592
 GL_OPERAND0_ALPHA                       equ 0x8598
 GL_OPERAND1_ALPHA                       equ 0x8599
 GL_OPERAND2_ALPHA                       equ 0x859A
 GL_RGB_SCALE                            equ 0x8573
 GL_ADD_SIGNED                           equ 0x8574
 GL_INTERPOLATE                          equ 0x8575
 GL_SUBTRACT                             equ 0x84E7
 GL_CONSTANT                             equ 0x8576
 GL_PRIMARY_COLOR                        equ 0x8577
 GL_PREVIOUS                             equ 0x8578
; texture_env_dot3 
 GL_DOT3_RGB                             equ 0x86AE
 GL_DOT3_RGBA                            equ 0x86AF
; texture_border_clamp 
 GL_CLAMP_TO_BORDER                      equ 0x812D

;прототипы функций opengl32.dll
extern _wglUseFontOutlinesW@32
extern _wglUseFontOutlinesA@32
extern _wglUseFontBitmapsW@16
extern _wglUseFontBitmapsA@16
extern _wglSwapLayerBuffers@8
extern _wglSwapBuffers@4
extern _wglShareLists@8
extern _wglSetPixelFormat@12
extern _wglSetLayerPaletteEntries@20
extern _wglRealizeLayerPalette@12
extern _wglMakeCurrent@8
extern _wglGetProcAddress@4
extern _wglGetPixelFormat@4
extern _wglGetLayerPaletteEntries@20
extern _wglGetDefaultProcAddress@4
extern _wglGetCurrentDC@0
extern _wglGetCurrentContext@0
extern _wglDescribePixelFormat@16
extern _wglDescribeLayerPlane@20
extern _wglDeleteContext@4
extern _wglCreateLayerContext@8
extern _wglCreateContext@4
extern _wglCopyContext@12
extern _wglChoosePixelFormat@8
extern _glViewport@16
extern _glVertexPointer@16
extern _glVertex4sv@4
extern _glVertex4s@16
extern _glVertex4iv@4
extern _glVertex4i@16
extern _glVertex4fv@4
extern _glVertex4f@16
extern _glVertex4dv@4
extern _glVertex4d@32
extern _glVertex3sv@4
extern _glVertex3s@12
extern _glVertex3iv@4
extern _glVertex3i@12
extern _glVertex3fv@4
extern _glVertex3f@12
extern _glVertex3dv@4
extern _glVertex3d@24
extern _glVertex2sv@4
extern _glVertex2s@8
extern _glVertex2iv@4
extern _glVertex2i@8
extern _glVertex2fv@4
extern _glVertex2f@8
extern _glVertex2dv@4
extern _glVertex2d@16
extern _glTranslatef@12
extern _glTranslated@24
extern _glTexSubImage2D@36
extern _glTexSubImage1D@28
extern _glTexParameteriv@12
extern _glTexParameteri@12
extern _glTexParameterfv@12
extern _glTexParameterf@12
extern _glTexImage2D@36
extern _glTexImage1D@32
extern _glTexGeniv@12
extern _glTexGeni@12
extern _glTexGenfv@12
extern _glTexGenf@12
extern _glTexGendv@12
extern _glTexGend@16
extern _glTexEnviv@12
extern _glTexEnvi@12
extern _glTexEnvfv@12
extern _glTexEnvf@12
extern _glTexCoordPointer@16
extern _glTexCoord4sv@4
extern _glTexCoord4s@16
extern _glTexCoord4iv@4
extern _glTexCoord4i@16
extern _glTexCoord4fv@4
extern _glTexCoord4f@16
extern _glTexCoord4dv@4
extern _glTexCoord4d@32
extern _glTexCoord3sv@4
extern _glTexCoord3s@12
extern _glTexCoord3iv@4
extern _glTexCoord3i@12
extern _glTexCoord3fv@4
extern _glTexCoord3f@12
extern _glTexCoord3dv@4
extern _glTexCoord3d@24
extern _glTexCoord2sv@4
extern _glTexCoord2s@8
extern _glTexCoord2iv@4
extern _glTexCoord2i@8
extern _glTexCoord2fv@4
extern _glTexCoord2f@8
extern _glTexCoord2dv@4
extern _glTexCoord2d@16
extern _glTexCoord1sv@4
extern _glTexCoord1s@4
extern _glTexCoord1iv@4
extern _glTexCoord1i@4
extern _glTexCoord1fv@4
extern _glTexCoord1f@4
extern _glTexCoord1dv@4
extern _glTexCoord1d@8
extern _glStencilOp@12
extern _glStencilMask@4
extern _glStencilFunc@12
extern _glShadeModel@4
extern _glSelectBuffer@8
extern _glScissor@16
extern _glScalef@12
extern _glScaled@24
extern _glRotatef@16
extern _glRotated@32
extern _glRenderMode@4
extern _glRectsv@8
extern _glRects@16
extern _glRectiv@8
extern _glRecti@16
extern _glRectfv@8
extern _glRectf@16
extern _glRectdv@8
extern _glRectd@32
extern _glReadPixels@28
extern _glReadBuffer@4
extern _glRasterPos4sv@4
extern _glRasterPos4s@16
extern _glRasterPos4iv@4
extern _glRasterPos4i@16
extern _glRasterPos4fv@4
extern _glRasterPos4f@16
extern _glRasterPos4dv@4
extern _glRasterPos4d@32
extern _glRasterPos3sv@4
extern _glRasterPos3s@12
extern _glRasterPos3iv@4
extern _glRasterPos3i@12
extern _glRasterPos3fv@4
extern _glRasterPos3f@12
extern _glRasterPos3dv@4
extern _glRasterPos3d@24
extern _glRasterPos2sv@4
extern _glRasterPos2s@8
extern _glRasterPos2iv@4
extern _glRasterPos2i@8
extern _glRasterPos2fv@4
extern _glRasterPos2f@8
extern _glRasterPos2dv@4
extern _glRasterPos2d@16
extern _glPushName@4
extern _glPushMatrix@0
extern _glPushClientAttrib@4
extern _glPushAttrib@4
extern _glPrioritizeTextures@12
extern _glPopName@0
extern _glPopMatrix@0
extern _glPopClientAttrib@0
extern _glPopAttrib@0
extern _glPolygonStipple@4
extern _glPolygonOffset@8
extern _glPolygonMode@8
extern _glPointSize@4
extern _glPixelZoom@8
extern _glPixelTransferi@8
extern _glPixelTransferf@8
extern _glPixelStorei@8
extern _glPixelStoref@8
extern _glPixelMapusv@12
extern _glPixelMapuiv@12
extern _glPixelMapfv@12
extern _glPassThrough@4
extern _glOrtho@48
extern _glNormalPointer@12
extern _glNormal3sv@4
extern _glNormal3s@12
extern _glNormal3iv@4
extern _glNormal3i@12
extern _glNormal3fv@4
extern _glNormal3f@12
extern _glNormal3dv@4
extern _glNormal3d@24
extern _glNormal3bv@4
extern _glNormal3b@12
extern _glNewList@8
extern _glMultMatrixf@4
extern _glMultMatrixd@4
extern _glMatrixMode@4
extern _glMaterialiv@12
extern _glMateriali@12
extern _glMaterialfv@12
extern _glMaterialf@12
extern _glMapGrid2f@24
extern _glMapGrid2d@40
extern _glMapGrid1f@12
extern _glMapGrid1d@20
extern _glMap2f@40
extern _glMap2d@56
extern _glMap1f@24
extern _glMap1d@32
extern _glLogicOp@4
extern _glLoadName@4
extern _glLoadMatrixf@4
extern _glLoadMatrixd@4
extern _glLoadIdentity@0
extern _glListBase@4
extern _glLineWidth@4
extern _glLineStipple@8
extern _glLightiv@12
extern _glLighti@12
extern _glLightfv@12
extern _glLightf@12
extern _glLightModeliv@8
extern _glLightModeli@8
extern _glLightModelfv@8
extern _glLightModelf@8
extern _glIsTexture@4
extern _glIsList@4
extern _glIsEnabled@4
extern _glInterleavedArrays@12
extern _glInitNames@0
extern _glIndexubv@4
extern _glIndexub@4
extern _glIndexsv@4
extern _glIndexs@4
extern _glIndexiv@4
extern _glIndexi@4
extern _glIndexfv@4
extern _glIndexf@4
extern _glIndexdv@4
extern _glIndexd@8
extern _glIndexPointer@12
extern _glIndexMask@4
extern _glHint@8
extern _glGetTexParameteriv@12
extern _glGetTexParameterfv@12
extern _glGetTexLevelParameteriv@16
extern _glGetTexLevelParameterfv@16
extern _glGetTexImage@20
extern _glGetTexGeniv@12
extern _glGetTexGenfv@12
extern _glGetTexGendv@12
extern _glGetTexEnviv@12
extern _glGetTexEnvfv@12
extern _glGetString@4
extern _glGetPolygonStipple@4
extern _glGetPointerv@8
extern _glGetPixelMapusv@8
extern _glGetPixelMapuiv@8
extern _glGetPixelMapfv@8
extern _glGetMaterialiv@12
extern _glGetMaterialfv@12
extern _glGetMapiv@12
extern _glGetMapfv@12
extern _glGetMapdv@12
extern _glGetLightiv@12
extern _glGetLightfv@12
extern _glGetIntegerv@8
extern _glGetFloatv@8
extern _glGetError@0
extern _glGetDoublev@8
extern _glGetClipPlane@8
extern _glGetBooleanv@8
extern _glGenTextures@8
extern _glGenLists@4
extern _glFrustum@48
extern _glFrontFace@4
extern _glFogiv@8
extern _glFogi@8
extern _glFogfv@8
extern _glFogf@8
extern _glFlush@0
extern _glFinish@0
extern _glFeedbackBuffer@12
extern _glEvalPoint2@8
extern _glEvalPoint1@4
extern _glEvalMesh2@20
extern _glEvalMesh1@12
extern _glEvalCoord2fv@4
extern _glEvalCoord2f@8
extern _glEvalCoord2dv@4
extern _glEvalCoord2d@16
extern _glEvalCoord1fv@4
extern _glEvalCoord1f@4
extern _glEvalCoord1dv@4
extern _glEvalCoord1d@8
extern _glEndList@0
extern _glEnd@0
extern _glEnableClientState@4
extern _glEnable@4
extern _glEdgeFlagv@4
extern _glEdgeFlagPointer@8
extern _glEdgeFlag@4
extern _glDrawPixels@20
extern _glDrawElements@16
extern _glDrawBuffer@4
extern _glDrawArrays@12
extern _glDisableClientState@4
extern _glDisable@4
extern _glDepthRange@16
extern _glDepthMask@4
extern _glDepthFunc@4
extern _glDeleteTextures@8
extern _glDeleteLists@8
extern _glDebugEntry@8
extern _glCullFace@4
extern _glCopyTexSubImage2D@32
extern _glCopyTexSubImage1D@24
extern _glCopyTexImage2D@32
extern _glCopyTexImage1D@28
extern _glCopyPixels@20
extern _glColorPointer@16
extern _glColorMaterial@8
extern _glColorMask@16
extern _glColor4usv@4
extern _glColor4us@16
extern _glColor4uiv@4
extern _glColor4ui@16
extern _glColor4ubv@4
extern _glColor4ub@16
extern _glColor4sv@4
extern _glColor4s@16
extern _glColor4iv@4
extern _glColor4i@16
extern _glColor4fv@4
extern _glColor4f@16
extern _glColor4dv@4
extern _glColor4d@32
extern _glColor4bv@4
extern _glColor4b@16
extern _glColor3usv@4
extern _glColor3us@12
extern _glColor3uiv@4
extern _glColor3ui@12
extern _glColor3ubv@4
extern _glColor3ub@12
extern _glColor3sv@4
extern _glColor3s@12
extern _glColor3iv@4
extern _glColor3i@12
extern _glColor3fv@4
extern _glColor3f@12
extern _glColor3dv@4
extern _glColor3d@24
extern _glColor3bv@4
extern _glColor3b@12
extern _glClipPlane@8
extern _glClearStencil@4
extern _glClearIndex@4
extern _glClearDepth@8
extern _glClearColor@16
extern _glClearAccum@16
extern _glClear@4
extern _glCallLists@12
extern _glCallList@4
extern _glBlendFunc@8
extern _glBitmap@28
extern _glBindTexture@8
extern _glBegin@4
extern _glArrayElement@4
extern _glAreTexturesResident@12
extern _glAlphaFunc@8
extern _glAccum@8
extern _GlmfPlayGlsRecord@16
extern _GlmfInitPlayback@12
extern _GlmfEndPlayback@4
extern _GlmfEndGlsBlock@4
extern _GlmfCloseMetaFile@4
extern _GlmfBeginGlsBlock@4

/**
  ******************************************************************************
  * @file    network.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Tue Apr  7 14:45:28 2026
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */


#include "network.h"
#include "network_data.h"

#include "ai_platform.h"
#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "core_convert.h"

#include "layers.h"



#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_network
 
#undef AI_NETWORK_MODEL_SIGNATURE
#define AI_NETWORK_MODEL_SIGNATURE     "0x41ebf65eca96436bc728046afc2daae5"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Tue Apr  7 14:45:28 2026"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_NETWORK_N_BATCHES
#define AI_NETWORK_N_BATCHES         (1)

static ai_ptr g_network_activations_map[1] = AI_C_ARRAY_INIT;
static ai_ptr g_network_weights_map[1] = AI_C_ARRAY_INIT;



/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  serving_default_keras_tensor0_output_array, AI_ARRAY_FORMAT_S8|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 30, AI_STATIC)

/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 320, AI_STATIC)

/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  pad_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 36, AI_STATIC)

/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 320, AI_STATIC)

/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  pad_5_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 384, AI_STATIC)

/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 320, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_11_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 320, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  pad_12_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 448, AI_STATIC)

/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  pad_12_0_conversion_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 448, AI_STATIC)

/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 320, AI_STATIC)

/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_0_0_eltwise_18_conversion_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 320, AI_STATIC)

/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_18_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 320, AI_STATIC)

/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  pad_19_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 448, AI_STATIC)

/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  pad_19_0_0_conv2d_22_conversion_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 448, AI_STATIC)

/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 320, AI_STATIC)

/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_0_0_eltwise_25_conversion_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 320, AI_STATIC)

/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_25_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 320, AI_STATIC)

/* Array#17 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_27_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 320, AI_STATIC)

/* Array#18 */
AI_ARRAY_OBJ_DECLARE(
  pad_28_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 576, AI_STATIC)

/* Array#19 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_31_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 640, AI_STATIC)

/* Array#20 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_31_pad_before_0_0_conv2d_31_conversion_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 640, AI_STATIC)

/* Array#21 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_31_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 320, AI_STATIC)

/* Array#22 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_31_0_0_eltwise_34_conversion_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 320, AI_STATIC)

/* Array#23 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_34_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 320, AI_STATIC)

/* Array#24 */
AI_ARRAY_OBJ_DECLARE(
  pad_35_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 576, AI_STATIC)

/* Array#25 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_38_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 640, AI_STATIC)

/* Array#26 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_38_pad_before_0_0_conv2d_38_conversion_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 640, AI_STATIC)

/* Array#27 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_38_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 320, AI_STATIC)

/* Array#28 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_38_0_0_eltwise_41_conversion_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 320, AI_STATIC)

/* Array#29 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_41_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 320, AI_STATIC)

/* Array#30 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_26_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 320, AI_STATIC)

/* Array#31 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_42_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 320, AI_STATIC)

/* Array#32 */
AI_ARRAY_OBJ_DECLARE(
  slice_43_gather_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32, AI_STATIC)

/* Array#33 */
AI_ARRAY_OBJ_DECLARE(
  gemm_44_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32, AI_STATIC)

/* Array#34 */
AI_ARRAY_OBJ_DECLARE(
  gemm_45_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16, AI_STATIC)

/* Array#35 */
AI_ARRAY_OBJ_DECLARE(
  gemm_46_output_array, AI_ARRAY_FORMAT_S8|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 1, AI_STATIC)

/* Array#36 */
AI_ARRAY_OBJ_DECLARE(
  slice_43_gather_0_placeholder_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 1, AI_STATIC)

/* Array#37 */
AI_ARRAY_OBJ_DECLARE(
  tfl_pseudo_qconst6_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32, AI_STATIC)

/* Array#38 */
AI_ARRAY_OBJ_DECLARE(
  tfl_pseudo_qconst8_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32, AI_STATIC)

/* Array#39 */
AI_ARRAY_OBJ_DECLARE(
  tfl_pseudo_qconst10_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32, AI_STATIC)

/* Array#40 */
AI_ARRAY_OBJ_DECLARE(
  tfl_pseudo_qconst12_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32, AI_STATIC)

/* Array#41 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 96, AI_STATIC)

/* Array#42 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#43 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 288, AI_STATIC)

/* Array#44 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#45 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3072, AI_STATIC)

/* Array#46 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#47 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3072, AI_STATIC)

/* Array#48 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#49 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3072, AI_STATIC)

/* Array#50 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_31_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3072, AI_STATIC)

/* Array#51 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_38_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3072, AI_STATIC)

/* Array#52 */
AI_ARRAY_OBJ_DECLARE(
  gemm_44_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)

/* Array#53 */
AI_ARRAY_OBJ_DECLARE(
  gemm_44_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#54 */
AI_ARRAY_OBJ_DECLARE(
  gemm_45_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#55 */
AI_ARRAY_OBJ_DECLARE(
  gemm_45_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#56 */
AI_ARRAY_OBJ_DECLARE(
  gemm_46_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16, AI_STATIC)

/* Array#57 */
AI_ARRAY_OBJ_DECLARE(
  gemm_46_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 1, AI_STATIC)

/* Array#58 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 332, AI_STATIC)

/* Array#59 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1060, AI_STATIC)

/* Array#60 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5952, AI_STATIC)

/* Array#61 */
AI_ARRAY_OBJ_DECLARE(
  gemm_44_scratch0_array, AI_ARRAY_FORMAT_S16,
  NULL, NULL, 192, AI_STATIC)

/* Array#62 */
AI_ARRAY_OBJ_DECLARE(
  gemm_45_scratch0_array, AI_ARRAY_FORMAT_S16,
  NULL, NULL, 112, AI_STATIC)

/* Array#63 */
AI_ARRAY_OBJ_DECLARE(
  gemm_46_scratch0_array, AI_ARRAY_FORMAT_S16,
  NULL, NULL, 16, AI_STATIC)

/**  Array metadata declarations section  *************************************/
/* Int quant #0 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_38_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.045740675181150436f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #1 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_38_0_0_eltwise_41_conversion_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.061327505856752396f),
    AI_PACK_INTQ_ZP(15)))

/* Int quant #2 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_41_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.026781708002090454f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #3 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_26_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.044078510254621506f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #4 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_42_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.044078510254621506f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #5 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(slice_43_gather_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.044078510254621506f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #6 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(gemm_44_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.03233354911208153f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #7 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(gemm_45_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.024512015283107758f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #8 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(gemm_46_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.013602732680737972f),
    AI_PACK_INTQ_ZP(48)))

/* Int quant #9 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(tfl_pseudo_qconst6_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0002962581056635827f),
    AI_PACK_INTQ_ZP(31)))

/* Int quant #10 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(tfl_pseudo_qconst8_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00047394371358677745f),
    AI_PACK_INTQ_ZP(12)))

/* Int quant #11 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(tfl_pseudo_qconst10_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0003655589243862778f),
    AI_PACK_INTQ_ZP(11)))

/* Int quant #12 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(tfl_pseudo_qconst12_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0007116021006368101f),
    AI_PACK_INTQ_ZP(-51)))

/* Int quant #13 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008441309444606304f, 0.01303805410861969f, 0.005011218134313822f, 0.012994103133678436f, 0.00981566309928894f, 0.004567618016153574f, 0.0134872542694211f, 0.00916330050677061f, 0.010001890361309052f, 0.010427938774228096f, 0.008487818762660027f, 0.0071676489897072315f, 0.013155984692275524f, 0.009437444619834423f, 0.0031337146647274494f, 0.008284371346235275f, 0.011039331555366516f, 0.007425997406244278f, 0.007341540418565273f, 0.01123123336583376f, 0.010970032773911953f, 0.012017128057777882f, 0.004711824469268322f, 0.006493429187685251f, 0.011422603391110897f, 0.003787910332903266f, 0.00552598899230361f, 0.007099390961229801f, 0.012122562155127525f, 0.014531086198985577f, 0.007187281735241413f, 0.008681467734277248f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #14 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00695073651149869f, 0.00815861951559782f, 0.007123659364879131f, 0.004982537589967251f, 0.005743212066590786f, 0.004692348185926676f, 0.007275102660059929f, 0.00501048332080245f, 0.007163202855736017f, 0.006700143683701754f, 0.004281149245798588f, 0.006536178290843964f, 0.005918070208281279f, 0.00726324412971735f, 0.007052823435515165f, 0.0028564278036355972f, 0.006419974844902754f, 0.0060532912611961365f, 0.006692970637232065f, 0.0037863380275666714f, 0.004674551542848349f, 0.007993796840310097f, 0.00657263770699501f, 0.006201275624334812f, 0.004521867260336876f, 0.007863006554543972f, 0.005853824783116579f, 0.006766115315258503f, 0.005558129400014877f, 0.004251702688634396f, 0.006245884113013744f, 0.007248655892908573f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #15 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_7_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0024739368818700314f, 0.0027849331963807344f, 0.0025042167399078608f, 0.002468452090397477f, 0.002550400560721755f, 0.0026340412441641092f, 0.002797089982777834f, 0.0027038780972361565f, 0.00258931634016335f, 0.0024384341668337584f, 0.0025460647884756327f, 0.0025795060209929943f, 0.0024984427727758884f, 0.0025630081072449684f, 0.0026238912250846624f, 0.002865726128220558f, 0.0025312250945717096f, 0.0026468303985893726f, 0.0023060310631990433f, 0.0025005803909152746f, 0.00230708671733737f, 0.0025076894089579582f, 0.0026766229420900345f, 0.0023859499488025904f, 0.002547175856307149f, 0.0024803990963846445f, 0.002632361836731434f, 0.002428966574370861f, 0.0026525186840444803f, 0.00270083942450583f, 0.002609497867524624f, 0.002460642484948039f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #16 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(gemm_44_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.002514552092179656f, 0.002391138346865773f, 0.0026036843191832304f, 0.0026964377611875534f, 0.002230070298537612f, 0.002663991879671812f, 0.0023839150089770555f, 0.0022936598397791386f, 0.0021195777226239443f, 0.002963107079267502f, 0.002414274262264371f, 0.002482419600710273f, 0.0025088689289987087f, 0.0024720795918256044f, 0.0022614141926169395f, 0.002552654128521681f, 0.002332481322810054f, 0.0021952528040856123f, 0.0023790060076862574f, 0.002423920901492238f, 0.002344655804336071f, 0.002428786363452673f, 0.002376401796936989f, 0.0021807134617120028f, 0.0021654388401657343f, 0.002191794803366065f, 0.0023715710267424583f, 0.002338673919439316f, 0.002323995577171445f, 0.0024774314370006323f, 0.0025218564551323652f, 0.002467094687744975f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #17 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(serving_default_keras_tensor0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.052326250821352005f),
    AI_PACK_INTQ_ZP(62)))

/* Int quant #18 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.12477877736091614f),
    AI_PACK_INTQ_ZP(7)))

/* Int quant #19 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(gemm_45_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.002549987519159913f, 0.0028389550279825926f, 0.0026937639340758324f, 0.0027341549284756184f, 0.0028729927726089954f, 0.0027535767294466496f, 0.002891076495870948f, 0.0029664223548024893f, 0.0023701388854533434f, 0.0026192646473646164f, 0.0024509222712367773f, 0.0025166634004563093f, 0.0027388655580580235f, 0.0027379782404750586f, 0.002484380267560482f, 0.002860176144167781f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #20 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(pad_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.052326250821352005f),
    AI_PACK_INTQ_ZP(62)))

/* Int quant #21 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.03943430259823799f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #22 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(pad_5_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.03943430259823799f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #23 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(gemm_46_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004554642364382744f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #24 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_7_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.02354486659169197f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #25 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_11_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06249023973941803f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #26 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(pad_12_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06249023973941803f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #27 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_0_0_eltwise_18_conversion_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09442955255508423f),
    AI_PACK_INTQ_ZP(13)))

/* Int quant #28 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_18_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0423600897192955f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #29 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(pad_19_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0423600897192955f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #30 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_22_0_0_eltwise_25_conversion_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04988274723291397f),
    AI_PACK_INTQ_ZP(25)))

/* Int quant #31 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_25_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.019858907908201218f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #32 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_27_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06249023973941803f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #33 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(pad_28_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06249023973941803f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #34 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_31_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06249023973941803f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #35 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_31_0_0_eltwise_34_conversion_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.11015850305557251f),
    AI_PACK_INTQ_ZP(17)))

/* Int quant #36 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_34_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.045740675181150436f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #37 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(pad_35_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.045740675181150436f),
    AI_PACK_INTQ_ZP(-128)))

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_pad_before_output, AI_STATIC,
  0, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 20), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &conv2d_38_pad_before_output_array, &conv2d_38_pad_before_output_array_intq)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_pad_before_0_0_conv2d_38_conversion_output, AI_STATIC,
  1, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 20), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_38_pad_before_0_0_conv2d_38_conversion_output_array, NULL)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_output, AI_STATIC,
  2, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 10), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_38_output_array, NULL)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_0_0_eltwise_41_conversion_output, AI_STATIC,
  3, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 10), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &conv2d_38_0_0_eltwise_41_conversion_output_array, &conv2d_38_0_0_eltwise_41_conversion_output_array_intq)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_41_output, AI_STATIC,
  4, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 10), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &eltwise_41_output_array, &eltwise_41_output_array_intq)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_26_output, AI_STATIC,
  5, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 10), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &eltwise_26_output_array, &eltwise_26_output_array_intq)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_42_output, AI_STATIC,
  6, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 10), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &eltwise_42_output_array, &eltwise_42_output_array_intq)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  slice_43_gather_0_output, AI_STATIC,
  7, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &slice_43_gather_0_output_array, &slice_43_gather_0_output_array_intq)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  gemm_44_output, AI_STATIC,
  8, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &gemm_44_output_array, &gemm_44_output_array_intq)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  gemm_45_output, AI_STATIC,
  9, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 1, 1, 16, 16),
  1, &gemm_45_output_array, &gemm_45_output_array_intq)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  gemm_46_output, AI_STATIC,
  10, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &gemm_46_output_array, &gemm_46_output_array_intq)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  slice_43_gather_0_placeholder, AI_STATIC,
  11, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &slice_43_gather_0_placeholder_array, NULL)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  tfl_pseudo_qconst6, AI_STATIC,
  12, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &tfl_pseudo_qconst6_array, &tfl_pseudo_qconst6_array_intq)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  tfl_pseudo_qconst8, AI_STATIC,
  13, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &tfl_pseudo_qconst8_array, &tfl_pseudo_qconst8_array_intq)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  tfl_pseudo_qconst10, AI_STATIC,
  14, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &tfl_pseudo_qconst10_array, &tfl_pseudo_qconst10_array_intq)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  tfl_pseudo_qconst12, AI_STATIC,
  15, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &tfl_pseudo_qconst12_array, &tfl_pseudo_qconst12_array_intq)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_weights, AI_STATIC,
  16, 0x1,
  AI_SHAPE_INIT(4, 3, 1, 1, 32), AI_STRIDE_INIT(4, 1, 3, 96, 96),
  1, &conv2d_9_weights_array, &conv2d_9_weights_array_intq)

/* Tensor #17 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_bias, AI_STATIC,
  17, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_9_bias_array, NULL)

/* Tensor #18 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_weights, AI_STATIC,
  18, 0x1,
  AI_SHAPE_INIT(4, 3, 3, 1, 32), AI_STRIDE_INIT(4, 1, 3, 96, 288),
  1, &conv2d_3_weights_array, &conv2d_3_weights_array_intq)

/* Tensor #19 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_bias, AI_STATIC,
  19, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_3_bias_array, NULL)

/* Tensor #20 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_weights, AI_STATIC,
  20, 0x1,
  AI_SHAPE_INIT(4, 32, 3, 1, 32), AI_STRIDE_INIT(4, 1, 32, 1024, 3072),
  1, &conv2d_7_weights_array, &conv2d_7_weights_array_intq)

/* Tensor #21 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_bias, AI_STATIC,
  21, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_7_bias_array, NULL)

/* Tensor #22 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_weights, AI_STATIC,
  22, 0x0,
  AI_SHAPE_INIT(4, 32, 1, 3, 32), AI_STRIDE_INIT(4, 4, 128, 4096, 4096),
  1, &conv2d_15_weights_array, NULL)

/* Tensor #23 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_bias, AI_STATIC,
  23, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_15_bias_array, NULL)

/* Tensor #24 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_weights, AI_STATIC,
  24, 0x0,
  AI_SHAPE_INIT(4, 32, 1, 3, 32), AI_STRIDE_INIT(4, 4, 128, 4096, 4096),
  1, &conv2d_22_weights_array, NULL)

/* Tensor #25 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_31_weights, AI_STATIC,
  25, 0x0,
  AI_SHAPE_INIT(4, 32, 1, 3, 32), AI_STRIDE_INIT(4, 4, 128, 4096, 4096),
  1, &conv2d_31_weights_array, NULL)

/* Tensor #26 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_weights, AI_STATIC,
  26, 0x0,
  AI_SHAPE_INIT(4, 32, 1, 3, 32), AI_STRIDE_INIT(4, 4, 128, 4096, 4096),
  1, &conv2d_38_weights_array, NULL)

/* Tensor #27 */
AI_TENSOR_OBJ_DECLARE(
  gemm_44_weights, AI_STATIC,
  27, 0x1,
  AI_SHAPE_INIT(4, 32, 32, 1, 1), AI_STRIDE_INIT(4, 1, 32, 1024, 1024),
  1, &gemm_44_weights_array, &gemm_44_weights_array_intq)

/* Tensor #28 */
AI_TENSOR_OBJ_DECLARE(
  gemm_44_bias, AI_STATIC,
  28, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &gemm_44_bias_array, NULL)

/* Tensor #29 */
AI_TENSOR_OBJ_DECLARE(
  serving_default_keras_tensor0_output, AI_STATIC,
  29, 0x1,
  AI_SHAPE_INIT(4, 1, 3, 1, 10), AI_STRIDE_INIT(4, 1, 1, 3, 3),
  1, &serving_default_keras_tensor0_output_array, &serving_default_keras_tensor0_output_array_intq)

/* Tensor #30 */
AI_TENSOR_OBJ_DECLARE(
  serving_default_keras_tensor0_output0, AI_STATIC,
  30, 0x1,
  AI_SHAPE_INIT(4, 1, 3, 10, 1), AI_STRIDE_INIT(4, 1, 1, 3, 30),
  1, &serving_default_keras_tensor0_output_array, &serving_default_keras_tensor0_output_array_intq)

/* Tensor #31 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_output, AI_STATIC,
  31, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 10, 1), AI_STRIDE_INIT(4, 1, 1, 32, 320),
  1, &conv2d_9_output_array, &conv2d_9_output_array_intq)

/* Tensor #32 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_output0, AI_STATIC,
  32, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 10), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &conv2d_9_output_array, &conv2d_9_output_array_intq)

/* Tensor #33 */
AI_TENSOR_OBJ_DECLARE(
  gemm_45_weights, AI_STATIC,
  33, 0x1,
  AI_SHAPE_INIT(4, 32, 16, 1, 1), AI_STRIDE_INIT(4, 1, 32, 512, 512),
  1, &gemm_45_weights_array, &gemm_45_weights_array_intq)

/* Tensor #34 */
AI_TENSOR_OBJ_DECLARE(
  pad_0_output, AI_STATIC,
  34, 0x1,
  AI_SHAPE_INIT(4, 1, 3, 1, 12), AI_STRIDE_INIT(4, 1, 1, 3, 3),
  1, &pad_0_output_array, &pad_0_output_array_intq)

/* Tensor #35 */
AI_TENSOR_OBJ_DECLARE(
  pad_0_output0, AI_STATIC,
  35, 0x1,
  AI_SHAPE_INIT(4, 1, 3, 12, 1), AI_STRIDE_INIT(4, 1, 1, 3, 36),
  1, &pad_0_output_array, &pad_0_output_array_intq)

/* Tensor #36 */
AI_TENSOR_OBJ_DECLARE(
  gemm_45_bias, AI_STATIC,
  36, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &gemm_45_bias_array, NULL)

/* Tensor #37 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_output, AI_STATIC,
  37, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 10, 1), AI_STRIDE_INIT(4, 1, 1, 32, 320),
  1, &conv2d_3_output_array, &conv2d_3_output_array_intq)

/* Tensor #38 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_output0, AI_STATIC,
  38, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 10), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &conv2d_3_output_array, &conv2d_3_output_array_intq)

/* Tensor #39 */
AI_TENSOR_OBJ_DECLARE(
  pad_5_output, AI_STATIC,
  39, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 12), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &pad_5_output_array, &pad_5_output_array_intq)

/* Tensor #40 */
AI_TENSOR_OBJ_DECLARE(
  pad_5_output0, AI_STATIC,
  40, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 12, 1), AI_STRIDE_INIT(4, 1, 1, 32, 384),
  1, &pad_5_output_array, &pad_5_output_array_intq)

/* Tensor #41 */
AI_TENSOR_OBJ_DECLARE(
  gemm_46_weights, AI_STATIC,
  41, 0x1,
  AI_SHAPE_INIT(4, 16, 1, 1, 1), AI_STRIDE_INIT(4, 1, 16, 16, 16),
  1, &gemm_46_weights_array, &gemm_46_weights_array_intq)

/* Tensor #42 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_output, AI_STATIC,
  42, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 10, 1), AI_STRIDE_INIT(4, 1, 1, 32, 320),
  1, &conv2d_7_output_array, &conv2d_7_output_array_intq)

/* Tensor #43 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_output0, AI_STATIC,
  43, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 10), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &conv2d_7_output_array, &conv2d_7_output_array_intq)

/* Tensor #44 */
AI_TENSOR_OBJ_DECLARE(
  gemm_46_bias, AI_STATIC,
  44, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &gemm_46_bias_array, NULL)

/* Tensor #45 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_11_output, AI_STATIC,
  45, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 10), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &eltwise_11_output_array, &eltwise_11_output_array_intq)

/* Tensor #46 */
AI_TENSOR_OBJ_DECLARE(
  pad_12_output, AI_STATIC,
  46, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 14), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &pad_12_output_array, &pad_12_output_array_intq)

/* Tensor #47 */
AI_TENSOR_OBJ_DECLARE(
  pad_12_0_conversion_output, AI_STATIC,
  47, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 14), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &pad_12_0_conversion_output_array, NULL)

/* Tensor #48 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_scratch0, AI_STATIC,
  48, 0x0,
  AI_SHAPE_INIT(4, 1, 332, 1, 1), AI_STRIDE_INIT(4, 1, 1, 332, 332),
  1, &conv2d_9_scratch0_array, NULL)

/* Tensor #49 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_output, AI_STATIC,
  49, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 10), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_15_output_array, NULL)

/* Tensor #50 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_0_0_eltwise_18_conversion_output, AI_STATIC,
  50, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 10), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &conv2d_15_0_0_eltwise_18_conversion_output_array, &conv2d_15_0_0_eltwise_18_conversion_output_array_intq)

/* Tensor #51 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_18_output, AI_STATIC,
  51, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 10), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &eltwise_18_output_array, &eltwise_18_output_array_intq)

/* Tensor #52 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_scratch0, AI_STATIC,
  52, 0x0,
  AI_SHAPE_INIT(4, 1, 1060, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1060, 1060),
  1, &conv2d_3_scratch0_array, NULL)

/* Tensor #53 */
AI_TENSOR_OBJ_DECLARE(
  pad_19_output, AI_STATIC,
  53, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 14), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &pad_19_output_array, &pad_19_output_array_intq)

/* Tensor #54 */
AI_TENSOR_OBJ_DECLARE(
  pad_19_0_0_conv2d_22_conversion_output, AI_STATIC,
  54, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 14), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &pad_19_0_0_conv2d_22_conversion_output_array, NULL)

/* Tensor #55 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_output, AI_STATIC,
  55, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 10), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_22_output_array, NULL)

/* Tensor #56 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_scratch0, AI_STATIC,
  56, 0x0,
  AI_SHAPE_INIT(4, 1, 5952, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5952, 5952),
  1, &conv2d_7_scratch0_array, NULL)

/* Tensor #57 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_0_0_eltwise_25_conversion_output, AI_STATIC,
  57, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 10), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &conv2d_22_0_0_eltwise_25_conversion_output_array, &conv2d_22_0_0_eltwise_25_conversion_output_array_intq)

/* Tensor #58 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_25_output, AI_STATIC,
  58, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 10), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &eltwise_25_output_array, &eltwise_25_output_array_intq)

/* Tensor #59 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_27_output, AI_STATIC,
  59, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 10), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &eltwise_27_output_array, &eltwise_27_output_array_intq)

/* Tensor #60 */
AI_TENSOR_OBJ_DECLARE(
  gemm_44_scratch0, AI_STATIC,
  60, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 2, 2, 384, 384),
  1, &gemm_44_scratch0_array, NULL)

/* Tensor #61 */
AI_TENSOR_OBJ_DECLARE(
  pad_28_output, AI_STATIC,
  61, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 18), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &pad_28_output_array, &pad_28_output_array_intq)

/* Tensor #62 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_31_pad_before_output, AI_STATIC,
  62, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 20), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &conv2d_31_pad_before_output_array, &conv2d_31_pad_before_output_array_intq)

/* Tensor #63 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_31_pad_before_0_0_conv2d_31_conversion_output, AI_STATIC,
  63, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 20), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_31_pad_before_0_0_conv2d_31_conversion_output_array, NULL)

/* Tensor #64 */
AI_TENSOR_OBJ_DECLARE(
  gemm_45_scratch0, AI_STATIC,
  64, 0x0,
  AI_SHAPE_INIT(4, 1, 112, 1, 1), AI_STRIDE_INIT(4, 2, 2, 224, 224),
  1, &gemm_45_scratch0_array, NULL)

/* Tensor #65 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_31_output, AI_STATIC,
  65, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 10), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_31_output_array, NULL)

/* Tensor #66 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_31_0_0_eltwise_34_conversion_output, AI_STATIC,
  66, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 10), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &conv2d_31_0_0_eltwise_34_conversion_output_array, &conv2d_31_0_0_eltwise_34_conversion_output_array_intq)

/* Tensor #67 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_34_output, AI_STATIC,
  67, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 10), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &eltwise_34_output_array, &eltwise_34_output_array_intq)

/* Tensor #68 */
AI_TENSOR_OBJ_DECLARE(
  gemm_46_scratch0, AI_STATIC,
  68, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 2, 2, 32, 32),
  1, &gemm_46_scratch0_array, NULL)

/* Tensor #69 */
AI_TENSOR_OBJ_DECLARE(
  pad_35_output, AI_STATIC,
  69, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 18), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &pad_35_output_array, &pad_35_output_array_intq)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  gemm_46_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_45_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_46_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &gemm_46_weights, &gemm_46_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_46_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  gemm_46_layer, 46,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense_integer_SSSA,
  &gemm_46_chain,
  NULL, &gemm_46_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  gemm_45_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_44_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_45_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &gemm_45_weights, &gemm_45_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_45_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  gemm_45_layer, 45,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense_integer_SSSA_ch,
  &gemm_45_chain,
  NULL, &gemm_46_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  gemm_44_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_43_gather_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_44_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &gemm_44_weights, &gemm_44_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_44_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  gemm_44_layer, 44,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense_integer_SSSA_ch,
  &gemm_44_chain,
  NULL, &gemm_45_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  slice_43_gather_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_42_output, &slice_43_gather_0_placeholder),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_43_gather_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  slice_43_gather_0_layer, 43,
  GATHER_TYPE, 0x0, NULL,
  gather, forward_gather,
  &slice_43_gather_0_chain,
  NULL, &gemm_44_layer, AI_STATIC, 
  .axis = AI_SHAPE_HEIGHT, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_42_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_26_output, &eltwise_41_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_42_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_42_layer, 42,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_42_chain,
  NULL, &slice_43_gather_0_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_26_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_7_output0, &eltwise_25_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_26_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_26_layer, 26,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_26_chain,
  NULL, &eltwise_42_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_41_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_38_0_0_eltwise_41_conversion_output, &tfl_pseudo_qconst6),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_41_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_41_layer, 41,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_41_chain,
  NULL, &eltwise_26_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_38_0_0_eltwise_41_conversion_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_38_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_38_0_0_eltwise_41_conversion_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_38_0_0_eltwise_41_conversion_layer, 38,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &conv2d_38_0_0_eltwise_41_conversion_chain,
  NULL, &eltwise_41_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_38_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_38_pad_before_0_0_conv2d_38_conversion_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_38_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_38_weights, &conv2d_15_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_38_layer, 38,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32_group,
  &conv2d_38_chain,
  NULL, &conv2d_38_0_0_eltwise_41_conversion_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 4), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_38_pad_before_0_0_conv2d_38_conversion_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_38_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_38_pad_before_0_0_conv2d_38_conversion_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_38_pad_before_0_0_conv2d_38_conversion_layer, 38,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &conv2d_38_pad_before_0_0_conv2d_38_conversion_chain,
  NULL, &conv2d_38_layer, AI_STATIC, 
)


AI_STATIC_CONST ai_i8 conv2d_38_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_38_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_38_pad_before_value_data, conv2d_38_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_38_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_35_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_38_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_38_pad_before_layer, 38,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_38_pad_before_chain,
  NULL, &conv2d_38_pad_before_0_0_conv2d_38_conversion_layer, AI_STATIC, 
  .value = &conv2d_38_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 0, 0, 2, 0), 
)


AI_STATIC_CONST ai_i8 pad_35_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    pad_35_value, AI_ARRAY_FORMAT_S8,
    pad_35_value_data, pad_35_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  pad_35_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_34_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_35_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  pad_35_layer, 35,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &pad_35_chain,
  NULL, &conv2d_38_pad_before_layer, AI_STATIC, 
  .value = &pad_35_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 8, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_34_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_31_0_0_eltwise_34_conversion_output, &tfl_pseudo_qconst8),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_34_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_34_layer, 34,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_34_chain,
  NULL, &pad_35_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_31_0_0_eltwise_34_conversion_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_31_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_31_0_0_eltwise_34_conversion_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_31_0_0_eltwise_34_conversion_layer, 31,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &conv2d_31_0_0_eltwise_34_conversion_chain,
  NULL, &eltwise_34_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_31_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_31_pad_before_0_0_conv2d_31_conversion_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_31_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_31_weights, &conv2d_15_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_31_layer, 31,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32_group,
  &conv2d_31_chain,
  NULL, &conv2d_31_0_0_eltwise_34_conversion_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 4), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_31_pad_before_0_0_conv2d_31_conversion_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_31_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_31_pad_before_0_0_conv2d_31_conversion_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_31_pad_before_0_0_conv2d_31_conversion_layer, 31,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &conv2d_31_pad_before_0_0_conv2d_31_conversion_chain,
  NULL, &conv2d_31_layer, AI_STATIC, 
)


AI_STATIC_CONST ai_i8 conv2d_31_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_31_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_31_pad_before_value_data, conv2d_31_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_31_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_28_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_31_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_31_pad_before_layer, 31,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_31_pad_before_chain,
  NULL, &conv2d_31_pad_before_0_0_conv2d_31_conversion_layer, AI_STATIC, 
  .value = &conv2d_31_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 0, 0, 2, 0), 
)


AI_STATIC_CONST ai_i8 pad_28_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    pad_28_value, AI_ARRAY_FORMAT_S8,
    pad_28_value_data, pad_28_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  pad_28_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_27_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_28_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  pad_28_layer, 28,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &pad_28_chain,
  NULL, &conv2d_31_pad_before_layer, AI_STATIC, 
  .value = &pad_28_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 8, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_27_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_11_output, &eltwise_25_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_27_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_27_layer, 27,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_27_chain,
  NULL, &pad_28_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_25_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_22_0_0_eltwise_25_conversion_output, &tfl_pseudo_qconst10),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_25_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_25_layer, 25,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_25_chain,
  NULL, &eltwise_27_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_22_0_0_eltwise_25_conversion_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_22_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_22_0_0_eltwise_25_conversion_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_22_0_0_eltwise_25_conversion_layer, 22,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &conv2d_22_0_0_eltwise_25_conversion_chain,
  NULL, &eltwise_25_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_22_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_19_0_0_conv2d_22_conversion_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_22_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_22_weights, &conv2d_15_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_22_layer, 22,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32_group,
  &conv2d_22_chain,
  NULL, &conv2d_22_0_0_eltwise_25_conversion_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 2), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  pad_19_0_0_conv2d_22_conversion_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_19_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_19_0_0_conv2d_22_conversion_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  pad_19_0_0_conv2d_22_conversion_layer, 19,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &pad_19_0_0_conv2d_22_conversion_chain,
  NULL, &conv2d_22_layer, AI_STATIC, 
)


AI_STATIC_CONST ai_i8 pad_19_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    pad_19_value, AI_ARRAY_FORMAT_S8,
    pad_19_value_data, pad_19_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  pad_19_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_18_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_19_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  pad_19_layer, 19,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &pad_19_chain,
  NULL, &pad_19_0_0_conv2d_22_conversion_layer, AI_STATIC, 
  .value = &pad_19_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 4, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_18_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_15_0_0_eltwise_18_conversion_output, &tfl_pseudo_qconst12),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_18_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_18_layer, 18,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_18_chain,
  NULL, &pad_19_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_15_0_0_eltwise_18_conversion_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_15_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_15_0_0_eltwise_18_conversion_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_15_0_0_eltwise_18_conversion_layer, 15,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &conv2d_15_0_0_eltwise_18_conversion_chain,
  NULL, &eltwise_18_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_15_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_12_0_conversion_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_15_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_15_weights, &conv2d_15_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_15_layer, 15,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32_group,
  &conv2d_15_chain,
  NULL, &conv2d_15_0_0_eltwise_18_conversion_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 2), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  pad_12_0_conversion_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_12_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_12_0_conversion_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  pad_12_0_conversion_layer, 12,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &pad_12_0_conversion_chain,
  NULL, &conv2d_15_layer, AI_STATIC, 
)


AI_STATIC_CONST ai_i8 pad_12_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    pad_12_value, AI_ARRAY_FORMAT_S8,
    pad_12_value_data, pad_12_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  pad_12_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_11_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_12_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  pad_12_layer, 12,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &pad_12_chain,
  NULL, &pad_12_0_conversion_layer, AI_STATIC, 
  .value = &pad_12_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 4, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_11_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_9_output0, &conv2d_7_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_11_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_11_layer, 11,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_11_chain,
  NULL, &pad_12_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_7_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_5_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_7_weights, &conv2d_7_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_7_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_7_layer, 7,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_deep_sssa8_ch,
  &conv2d_7_chain,
  NULL, &eltwise_11_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 pad_5_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    pad_5_value, AI_ARRAY_FORMAT_S8,
    pad_5_value_data, pad_5_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  pad_5_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_3_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_5_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  pad_5_layer, 5,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &pad_5_chain,
  NULL, &conv2d_7_layer, AI_STATIC, 
  .value = &pad_5_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 2, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_3_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_0_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_3_weights, &conv2d_3_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_3_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_3_layer, 3,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_sssa8_ch,
  &conv2d_3_chain,
  NULL, &pad_5_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 pad_0_value_data[] = { 62 };
AI_ARRAY_OBJ_DECLARE(
    pad_0_value, AI_ARRAY_FORMAT_S8,
    pad_0_value_data, pad_0_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  pad_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &serving_default_keras_tensor0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  pad_0_layer, 0,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &pad_0_chain,
  NULL, &conv2d_3_layer, AI_STATIC, 
  .value = &pad_0_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 2, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_9_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &serving_default_keras_tensor0_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_9_weights, &conv2d_9_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_9_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_9_layer, 9,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_9_chain,
  NULL, &pad_0_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


#if (AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 55000, 1, 1),
    55000, NULL, NULL),
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 6976, 1, 1),
    6976, NULL, NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_IN_NUM, &serving_default_keras_tensor0_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_OUT_NUM, &gemm_46_output),
  &conv2d_9_layer, 0x0542c3bd, NULL)

#else

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 55000, 1, 1),
      55000, NULL, NULL)
  ),
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 6976, 1, 1),
      6976, NULL, NULL)
  ),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_IN_NUM, &serving_default_keras_tensor0_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_OUT_NUM, &gemm_46_output),
  &conv2d_9_layer, 0x0542c3bd, NULL)

#endif	/*(AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)*/



/******************************************************************************/
AI_DECLARE_STATIC
ai_bool network_configure_activations(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_activations_map(g_network_activations_map, 1, params)) {
    /* Updating activations (byte) offsets */
    
    serving_default_keras_tensor0_output_array.data = AI_PTR(g_network_activations_map[0] + 652);
    serving_default_keras_tensor0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 652);
    conv2d_9_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 320);
    conv2d_9_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 320);
    conv2d_9_output_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_9_output_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    pad_0_output_array.data = AI_PTR(g_network_activations_map[0] + 320);
    pad_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 320);
    conv2d_3_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 356);
    conv2d_3_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 356);
    conv2d_3_output_array.data = AI_PTR(g_network_activations_map[0] + 1416);
    conv2d_3_output_array.data_start = AI_PTR(g_network_activations_map[0] + 1416);
    pad_5_output_array.data = AI_PTR(g_network_activations_map[0] + 320);
    pad_5_output_array.data_start = AI_PTR(g_network_activations_map[0] + 320);
    conv2d_7_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 704);
    conv2d_7_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 704);
    conv2d_7_output_array.data = AI_PTR(g_network_activations_map[0] + 6656);
    conv2d_7_output_array.data_start = AI_PTR(g_network_activations_map[0] + 6656);
    eltwise_11_output_array.data = AI_PTR(g_network_activations_map[0] + 320);
    eltwise_11_output_array.data_start = AI_PTR(g_network_activations_map[0] + 320);
    pad_12_output_array.data = AI_PTR(g_network_activations_map[0] + 640);
    pad_12_output_array.data_start = AI_PTR(g_network_activations_map[0] + 640);
    pad_12_0_conversion_output_array.data = AI_PTR(g_network_activations_map[0] + 1088);
    pad_12_0_conversion_output_array.data_start = AI_PTR(g_network_activations_map[0] + 1088);
    conv2d_15_output_array.data = AI_PTR(g_network_activations_map[0] + 2880);
    conv2d_15_output_array.data_start = AI_PTR(g_network_activations_map[0] + 2880);
    conv2d_15_0_0_eltwise_18_conversion_output_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_15_0_0_eltwise_18_conversion_output_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    eltwise_18_output_array.data = AI_PTR(g_network_activations_map[0] + 640);
    eltwise_18_output_array.data_start = AI_PTR(g_network_activations_map[0] + 640);
    pad_19_output_array.data = AI_PTR(g_network_activations_map[0] + 960);
    pad_19_output_array.data_start = AI_PTR(g_network_activations_map[0] + 960);
    pad_19_0_0_conv2d_22_conversion_output_array.data = AI_PTR(g_network_activations_map[0] + 1408);
    pad_19_0_0_conv2d_22_conversion_output_array.data_start = AI_PTR(g_network_activations_map[0] + 1408);
    conv2d_22_output_array.data = AI_PTR(g_network_activations_map[0] + 3200);
    conv2d_22_output_array.data_start = AI_PTR(g_network_activations_map[0] + 3200);
    conv2d_22_0_0_eltwise_25_conversion_output_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_22_0_0_eltwise_25_conversion_output_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    eltwise_25_output_array.data = AI_PTR(g_network_activations_map[0] + 640);
    eltwise_25_output_array.data_start = AI_PTR(g_network_activations_map[0] + 640);
    eltwise_27_output_array.data = AI_PTR(g_network_activations_map[0] + 0);
    eltwise_27_output_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    pad_28_output_array.data = AI_PTR(g_network_activations_map[0] + 960);
    pad_28_output_array.data_start = AI_PTR(g_network_activations_map[0] + 960);
    conv2d_31_pad_before_output_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_31_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_31_pad_before_0_0_conv2d_31_conversion_output_array.data = AI_PTR(g_network_activations_map[0] + 960);
    conv2d_31_pad_before_0_0_conv2d_31_conversion_output_array.data_start = AI_PTR(g_network_activations_map[0] + 960);
    conv2d_31_output_array.data = AI_PTR(g_network_activations_map[0] + 3520);
    conv2d_31_output_array.data_start = AI_PTR(g_network_activations_map[0] + 3520);
    conv2d_31_0_0_eltwise_34_conversion_output_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_31_0_0_eltwise_34_conversion_output_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    eltwise_34_output_array.data = AI_PTR(g_network_activations_map[0] + 320);
    eltwise_34_output_array.data_start = AI_PTR(g_network_activations_map[0] + 320);
    pad_35_output_array.data = AI_PTR(g_network_activations_map[0] + 960);
    pad_35_output_array.data_start = AI_PTR(g_network_activations_map[0] + 960);
    conv2d_38_pad_before_output_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_38_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_38_pad_before_0_0_conv2d_38_conversion_output_array.data = AI_PTR(g_network_activations_map[0] + 960);
    conv2d_38_pad_before_0_0_conv2d_38_conversion_output_array.data_start = AI_PTR(g_network_activations_map[0] + 960);
    conv2d_38_output_array.data = AI_PTR(g_network_activations_map[0] + 3520);
    conv2d_38_output_array.data_start = AI_PTR(g_network_activations_map[0] + 3520);
    conv2d_38_0_0_eltwise_41_conversion_output_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_38_0_0_eltwise_41_conversion_output_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    eltwise_41_output_array.data = AI_PTR(g_network_activations_map[0] + 320);
    eltwise_41_output_array.data_start = AI_PTR(g_network_activations_map[0] + 320);
    eltwise_26_output_array.data = AI_PTR(g_network_activations_map[0] + 0);
    eltwise_26_output_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    eltwise_42_output_array.data = AI_PTR(g_network_activations_map[0] + 640);
    eltwise_42_output_array.data_start = AI_PTR(g_network_activations_map[0] + 640);
    slice_43_gather_0_output_array.data = AI_PTR(g_network_activations_map[0] + 0);
    slice_43_gather_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    gemm_44_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 32);
    gemm_44_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 32);
    gemm_44_output_array.data = AI_PTR(g_network_activations_map[0] + 416);
    gemm_44_output_array.data_start = AI_PTR(g_network_activations_map[0] + 416);
    gemm_45_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    gemm_45_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    gemm_45_output_array.data = AI_PTR(g_network_activations_map[0] + 224);
    gemm_45_output_array.data_start = AI_PTR(g_network_activations_map[0] + 224);
    gemm_46_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    gemm_46_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    gemm_46_output_array.data = AI_PTR(g_network_activations_map[0] + 32);
    gemm_46_output_array.data_start = AI_PTR(g_network_activations_map[0] + 32);
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_ACTIVATIONS);
  return false;
}




/******************************************************************************/
AI_DECLARE_STATIC
ai_bool network_configure_weights(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_weights_map(g_network_weights_map, 1, params)) {
    /* Updating weights (byte) offsets */
    
    slice_43_gather_0_placeholder_array.format |= AI_FMT_FLAG_CONST;
    slice_43_gather_0_placeholder_array.data = AI_PTR(g_network_weights_map[0] + 0);
    slice_43_gather_0_placeholder_array.data_start = AI_PTR(g_network_weights_map[0] + 0);
    tfl_pseudo_qconst6_array.format |= AI_FMT_FLAG_CONST;
    tfl_pseudo_qconst6_array.data = AI_PTR(g_network_weights_map[0] + 4);
    tfl_pseudo_qconst6_array.data_start = AI_PTR(g_network_weights_map[0] + 4);
    tfl_pseudo_qconst8_array.format |= AI_FMT_FLAG_CONST;
    tfl_pseudo_qconst8_array.data = AI_PTR(g_network_weights_map[0] + 36);
    tfl_pseudo_qconst8_array.data_start = AI_PTR(g_network_weights_map[0] + 36);
    tfl_pseudo_qconst10_array.format |= AI_FMT_FLAG_CONST;
    tfl_pseudo_qconst10_array.data = AI_PTR(g_network_weights_map[0] + 68);
    tfl_pseudo_qconst10_array.data_start = AI_PTR(g_network_weights_map[0] + 68);
    tfl_pseudo_qconst12_array.format |= AI_FMT_FLAG_CONST;
    tfl_pseudo_qconst12_array.data = AI_PTR(g_network_weights_map[0] + 100);
    tfl_pseudo_qconst12_array.data_start = AI_PTR(g_network_weights_map[0] + 100);
    conv2d_9_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_9_weights_array.data = AI_PTR(g_network_weights_map[0] + 132);
    conv2d_9_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 132);
    conv2d_9_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_9_bias_array.data = AI_PTR(g_network_weights_map[0] + 228);
    conv2d_9_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 228);
    conv2d_3_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_3_weights_array.data = AI_PTR(g_network_weights_map[0] + 356);
    conv2d_3_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 356);
    conv2d_3_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_3_bias_array.data = AI_PTR(g_network_weights_map[0] + 644);
    conv2d_3_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 644);
    conv2d_7_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_7_weights_array.data = AI_PTR(g_network_weights_map[0] + 772);
    conv2d_7_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 772);
    conv2d_7_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_7_bias_array.data = AI_PTR(g_network_weights_map[0] + 3844);
    conv2d_7_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 3844);
    conv2d_15_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_15_weights_array.data = AI_PTR(g_network_weights_map[0] + 3972);
    conv2d_15_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 3972);
    conv2d_15_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_15_bias_array.data = AI_PTR(g_network_weights_map[0] + 16260);
    conv2d_15_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 16260);
    conv2d_22_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_22_weights_array.data = AI_PTR(g_network_weights_map[0] + 16388);
    conv2d_22_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 16388);
    conv2d_31_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_31_weights_array.data = AI_PTR(g_network_weights_map[0] + 28676);
    conv2d_31_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 28676);
    conv2d_38_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_38_weights_array.data = AI_PTR(g_network_weights_map[0] + 40964);
    conv2d_38_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 40964);
    gemm_44_weights_array.format |= AI_FMT_FLAG_CONST;
    gemm_44_weights_array.data = AI_PTR(g_network_weights_map[0] + 53252);
    gemm_44_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 53252);
    gemm_44_bias_array.format |= AI_FMT_FLAG_CONST;
    gemm_44_bias_array.data = AI_PTR(g_network_weights_map[0] + 54276);
    gemm_44_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 54276);
    gemm_45_weights_array.format |= AI_FMT_FLAG_CONST;
    gemm_45_weights_array.data = AI_PTR(g_network_weights_map[0] + 54404);
    gemm_45_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 54404);
    gemm_45_bias_array.format |= AI_FMT_FLAG_CONST;
    gemm_45_bias_array.data = AI_PTR(g_network_weights_map[0] + 54916);
    gemm_45_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 54916);
    gemm_46_weights_array.format |= AI_FMT_FLAG_CONST;
    gemm_46_weights_array.data = AI_PTR(g_network_weights_map[0] + 54980);
    gemm_46_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 54980);
    gemm_46_bias_array.format |= AI_FMT_FLAG_CONST;
    gemm_46_bias_array.data = AI_PTR(g_network_weights_map[0] + 54996);
    gemm_46_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 54996);
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_WEIGHTS);
  return false;
}


/**  PUBLIC APIs SECTION  *****************************************************/



AI_DEPRECATED
AI_API_ENTRY
ai_bool ai_network_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_NETWORK_MODEL_NAME,
      .model_signature   = AI_NETWORK_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 181025,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .params            = AI_STRUCT_INIT,
      .activations       = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0542c3bd,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}



AI_API_ENTRY
ai_bool ai_network_get_report(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_NETWORK_MODEL_NAME,
      .model_signature   = AI_NETWORK_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 181025,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .map_signature     = AI_MAGIC_SIGNATURE,
      .map_weights       = AI_STRUCT_INIT,
      .map_activations   = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0542c3bd,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}


AI_API_ENTRY
ai_error ai_network_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}


AI_API_ENTRY
ai_error ai_network_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    AI_CONTEXT_OBJ(&AI_NET_OBJ_INSTANCE),
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}


AI_API_ENTRY
ai_error ai_network_create_and_init(
  ai_handle* network, const ai_handle activations[], const ai_handle weights[])
{
  ai_error err;
  ai_network_params params;

  err = ai_network_create(network, AI_NETWORK_DATA_CONFIG);
  if (err.type != AI_ERROR_NONE) {
    return err;
  }
  
  if (ai_network_data_params_get(&params) != true) {
    err = ai_network_get_error(*network);
    return err;
  }
#if defined(AI_NETWORK_DATA_ACTIVATIONS_COUNT)
  /* set the addresses of the activations buffers */
  for (ai_u16 idx=0; activations && idx<params.map_activations.size; idx++) {
    AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_activations, idx, activations[idx]);
  }
#endif
#if defined(AI_NETWORK_DATA_WEIGHTS_COUNT)
  /* set the addresses of the weight buffers */
  for (ai_u16 idx=0; weights && idx<params.map_weights.size; idx++) {
    AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_weights, idx, weights[idx]);
  }
#endif
  if (ai_network_init(*network, &params) != true) {
    err = ai_network_get_error(*network);
  }
  return err;
}


AI_API_ENTRY
ai_buffer* ai_network_inputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    AI_NETWORK_OBJ(network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_inputs_get(network, n_buffer);
}


AI_API_ENTRY
ai_buffer* ai_network_outputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    AI_NETWORK_OBJ(network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_outputs_get(network, n_buffer);
}


AI_API_ENTRY
ai_handle ai_network_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}


AI_API_ENTRY
ai_bool ai_network_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = AI_NETWORK_OBJ(ai_platform_network_init(network, params));
  ai_bool ok = true;

  if (!net_ctx) return false;
  ok &= network_configure_weights(net_ctx, params);
  ok &= network_configure_activations(net_ctx, params);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_network_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}


AI_API_ENTRY
ai_i32 ai_network_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}



#undef AI_NETWORK_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME


//=============================================================================
//! @file ShadowBuilder.h
//!
//! @brief Build JSON strings.
//!
//! @copyright Copyright 2020 Laird
//!            All Rights Reserved.
//=============================================================================

#ifndef SHADOW_BUILDER_H
#define SHADOW_BUILDER_H

#ifdef __cplusplus
extern "C" {
#endif

//=============================================================================
// Includes
//=============================================================================
#include "Framework.h"

//=============================================================================
// Global Constants, Macros and Type Definitions
//=============================================================================
#define DO_MEMSET true
#define SKIP_MEMSET false

// IsNotString is true when the value isn't a string
#define SB_IS_NOT_STRING true
#define SB_IS_STRING false

//=============================================================================
// Global Data Definitions
//=============================================================================

//=============================================================================
// Global Function Prototypes
//=============================================================================

//-----------------------------------------------
//! @brief Reset the JSON buffer and add open brace '{'
//! @note If buffer was allocated from buffer pool then memset can be skipped.
//!
void ShadowBuilder_Start(JsonMsg_t *pJsonMsg, bool ClearBuffer);

//-----------------------------------------------
//! @brief Checks that last char was a ',' and adds closing brace '}'.
//!
void ShadowBuilder_Finalize(JsonMsg_t *pJsonMsg);

//-----------------------------------------------
//! @brief  Adds a JSON pair "key":<value> to the message being built.
//!
void ShadowBuilder_AddUint32(JsonMsg_t *pJsonMsg, const char *restrict pKey,
			     u32_t Value);
void ShadowBuilder_AddSigned32(JsonMsg_t *pJsonMsg, const char *restrict pKey,
			       s32_t Value);

//-----------------------------------------------
//! @brief  Adds a JSON pair to the message being built.
//!
//! @param  pKey, pValue  "<pKey>" : pValue
//!
//! @param  IsNotString is true when the value isn't a string.
//! This is used to properly format the output.
//! For example, "value:"string" or "value:1.
//!
void ShadowBuilder_AddPair(JsonMsg_t *pJsonMsg, const char *restrict pKey,
			   const char *restrict pValue, bool IsNotString);

//-----------------------------------------------
//! @brief  Adds a JSON version x.x.x
//!
//! @param  pKey, name of key
//!
void ShadowBuilder_AddVersion(JsonMsg_t *pJsonMsg, const char *restrict pKey,
			      u8_t Major, u8_t Minor, u8_t Build);

//-----------------------------------------------
//! @brief  Adds pair with true, false, or null
//!
//! @param  pKey, name of key
//!
void ShadowBuilder_AddNull(JsonMsg_t *pJsonMsg, const char *restrict pKey);
void ShadowBuilder_AddTrue(JsonMsg_t *pJsonMsg, const char *restrict pKey);
void ShadowBuilder_AddFalse(JsonMsg_t *pJsonMsg, const char *restrict pKey);

//-----------------------------------------------
//! @brief  Adds "pKey": [
//!
//! @param  pKey, name of key
//!
void ShadowBuilder_StartArray(JsonMsg_t *pJsonMsg, const char *restrict pKey);

//-----------------------------------------------
//! @brief  Closes JSON array
//!
void ShadowBuilder_EndArray(JsonMsg_t *pJsonMsg);

//-----------------------------------------------
//! @brief  Adds ["addr", epoch, true/false], to JSON buffer
//!
void ShadowBuilder_AddSensorTableArrayEntry(JsonMsg_t *pJsonMsg,
					    const char *restrict pAddrStr,
					    u32_t Epoch, bool Whitelisted);

//-----------------------------------------------
//! @brief  Adds "pKey": {
//!
//! @param  pKey, name of key
//!
void ShadowBuilder_StartGroup(JsonMsg_t *pJsonMsg, const char *restrict pKey);

//-----------------------------------------------
//! @brief  Closes JSON group
//!
void ShadowBuilder_EndGroup(JsonMsg_t *pJsonMsg);

#ifdef __cplusplus
}
#endif

#endif

// end

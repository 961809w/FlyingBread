// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Cookie.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef FLYINGBREAD_Cookie_generated_h
#error "Cookie.generated.h already included, missing '#pragma once' in Cookie.h"
#endif
#define FLYINGBREAD_Cookie_generated_h

#define FID_FlyingBread_Source_FlyingBread_Public_Cookie_h_10_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACookie(); \
	friend struct Z_Construct_UClass_ACookie_Statics; \
public: \
	DECLARE_CLASS(ACookie, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FlyingBread"), NO_API) \
	DECLARE_SERIALIZER(ACookie)


#define FID_FlyingBread_Source_FlyingBread_Public_Cookie_h_10_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ACookie(ACookie&&); \
	ACookie(const ACookie&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACookie); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACookie); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACookie) \
	NO_API virtual ~ACookie();


#define FID_FlyingBread_Source_FlyingBread_Public_Cookie_h_7_PROLOG
#define FID_FlyingBread_Source_FlyingBread_Public_Cookie_h_10_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_FlyingBread_Source_FlyingBread_Public_Cookie_h_10_INCLASS_NO_PURE_DECLS \
	FID_FlyingBread_Source_FlyingBread_Public_Cookie_h_10_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FLYINGBREAD_API UClass* StaticClass<class ACookie>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_FlyingBread_Source_FlyingBread_Public_Cookie_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

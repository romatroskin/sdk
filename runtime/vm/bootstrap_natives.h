// Copyright (c) 2012, the Dart project authors.  Please see the AUTHORS file
// for details. All rights reserved. Use of this source code is governed by a
// BSD-style license that can be found in the LICENSE file.

#ifndef VM_BOOTSTRAP_NATIVES_H_
#define VM_BOOTSTRAP_NATIVES_H_

#include "vm/native_entry.h"

// bootstrap dart natives used in the core dart library.

namespace dart {

// List of bootstrap native entry points used in the core dart library.
#define BOOTSTRAP_NATIVE_LIST(V)                                               \
  V(DartCore_fatal, 1)                                                         \
  V(Object_equals, 2)                                                          \
  V(Object_getHash, 1)                                                         \
  V(Object_setHash, 2)                                                         \
  V(Object_toString, 1)                                                        \
  V(Object_noSuchMethod, 6)                                                    \
  V(Object_runtimeType, 1)                                                     \
  V(Object_instanceOf, 4)                                                      \
  V(Object_instanceOfNum, 2)                                                   \
  V(Object_instanceOfInt, 2)                                                   \
  V(Object_instanceOfSmi, 2)                                                   \
  V(Object_instanceOfDouble, 2)                                                \
  V(Object_instanceOfString, 2)                                                \
  V(Object_as, 3)                                                              \
  V(Function_apply, 2)                                                         \
  V(Closure_equals, 2)                                                         \
  V(Closure_hashCode, 1)                                                       \
  V(Closure_clone, 1)                                                          \
  V(AbstractType_toString, 1)                                                  \
  V(Identical_comparison, 2)                                                   \
  V(Integer_bitAndFromInteger, 2)                                              \
  V(Integer_bitOrFromInteger, 2)                                               \
  V(Integer_bitXorFromInteger, 2)                                              \
  V(Integer_addFromInteger, 2)                                                 \
  V(Integer_subFromInteger, 2)                                                 \
  V(Integer_mulFromInteger, 2)                                                 \
  V(Integer_truncDivFromInteger, 2)                                            \
  V(Integer_moduloFromInteger, 2)                                              \
  V(Integer_greaterThanFromInteger, 2)                                         \
  V(Integer_equalToInteger, 2)                                                 \
  V(Integer_fromEnvironment, 3)                                                \
  V(Integer_parse, 1)                                                          \
  V(Bool_fromEnvironment, 3)                                                   \
  V(CapabilityImpl_factory, 1)                                                 \
  V(CapabilityImpl_equals, 2)                                                  \
  V(CapabilityImpl_get_hashcode, 1)                                            \
  V(RawReceivePortImpl_factory, 1)                                             \
  V(RawReceivePortImpl_get_id, 1)                                              \
  V(RawReceivePortImpl_get_sendport, 1)                                        \
  V(RawReceivePortImpl_closeInternal, 1)                                       \
  V(SendPortImpl_get_id, 1)                                                    \
  V(SendPortImpl_get_hashcode, 1)                                              \
  V(SendPortImpl_sendInternal_, 2)                                             \
  V(Smi_bitAndFromSmi, 2)                                                      \
  V(Smi_shlFromInt, 2)                                                         \
  V(Smi_shrFromInt, 2)                                                         \
  V(Smi_bitNegate, 1)                                                          \
  V(Smi_bitLength, 1)                                                          \
  V(Mint_bitNegate, 1)                                                         \
  V(Mint_bitLength, 1)                                                         \
  V(Mint_shlFromInt, 2)                                                        \
  V(Bigint_getNeg, 1)                                                          \
  V(Bigint_getUsed, 1)                                                         \
  V(Bigint_getDigits, 1)                                                       \
  V(Bigint_allocate, 4)                                                        \
  V(Developer_debugger, 2)                                                     \
  V(Developer_inspect, 1)                                                      \
  V(Developer_lookupExtension, 1)                                              \
  V(Developer_registerExtension, 2)                                            \
  V(Developer_log, 8)                                                          \
  V(Developer_postEvent, 2)                                                    \
  V(Double_getIsNegative, 1)                                                   \
  V(Double_getIsInfinite, 1)                                                   \
  V(Double_getIsNaN, 1)                                                        \
  V(Double_add, 2)                                                             \
  V(Double_sub, 2)                                                             \
  V(Double_mul, 2)                                                             \
  V(Double_div, 2)                                                             \
  V(Double_trunc_div, 2)                                                       \
  V(Double_remainder, 2)                                                       \
  V(Double_modulo, 2)                                                          \
  V(Double_greaterThanFromInteger, 2)                                          \
  V(Double_equalToInteger, 2)                                                  \
  V(Double_greaterThan, 2)                                                     \
  V(Double_equal, 2)                                                           \
  V(Double_doubleFromInteger, 2)                                               \
  V(Double_round, 1)                                                           \
  V(Double_floor, 1)                                                           \
  V(Double_ceil, 1)                                                            \
  V(Double_truncate, 1)                                                        \
  V(Double_toInt, 1)                                                           \
  V(Double_parse, 3)                                                           \
  V(Double_toString, 1)                                                        \
  V(Double_toStringAsFixed, 2)                                                 \
  V(Double_toStringAsExponential, 2)                                           \
  V(Double_toStringAsPrecision, 2)                                             \
  V(Double_flipSignBit, 1)                                                     \
  V(RegExp_factory, 4)                                                         \
  V(RegExp_getPattern, 1)                                                      \
  V(RegExp_getIsMultiLine, 1)                                                  \
  V(RegExp_getIsCaseSensitive, 1)                                              \
  V(RegExp_getGroupCount, 1)                                                   \
  V(RegExp_ExecuteMatch, 3)                                                    \
  V(List_allocate, 2)                                                          \
  V(List_getIndexed, 2)                                                        \
  V(List_setIndexed, 3)                                                        \
  V(List_getLength, 1)                                                         \
  V(List_slice, 4)                                                             \
  V(ImmutableList_from, 4)                                                     \
  V(StringBase_createFromCodePoints, 3)                                        \
  V(StringBase_substringUnchecked, 3)                                          \
  V(StringBase_joinReplaceAllResult, 4)                                        \
  V(StringBuffer_createStringFromUint16Array, 3)                               \
  V(OneByteString_substringUnchecked, 3)                                       \
  V(OneByteString_splitWithCharCode, 2)                                        \
  V(OneByteString_allocate, 1)                                                 \
  V(OneByteString_allocateFromOneByteList, 3)                                  \
  V(OneByteString_setAt, 3)                                                    \
  V(TwoByteString_allocateFromTwoByteList, 3)                                  \
  V(ExternalOneByteString_getCid, 0)                                           \
  V(String_getHashCode, 1)                                                     \
  V(String_getLength, 1)                                                       \
  V(String_charAt, 2)                                                          \
  V(String_codeUnitAt, 2)                                                      \
  V(String_concat, 2)                                                          \
  V(String_fromEnvironment, 3)                                                 \
  V(String_toLowerCase, 1)                                                     \
  V(String_toUpperCase, 1)                                                     \
  V(String_concatRange, 3)                                                     \
  V(Math_sqrt, 1)                                                              \
  V(Math_sin, 1)                                                               \
  V(Math_cos, 1)                                                               \
  V(Math_tan, 1)                                                               \
  V(Math_asin, 1)                                                              \
  V(Math_acos, 1)                                                              \
  V(Math_atan, 1)                                                              \
  V(Math_atan2, 2)                                                             \
  V(Math_exp, 1)                                                               \
  V(Math_log, 1)                                                               \
  V(Math_doublePow, 2)                                                         \
  V(Random_nextState, 1)                                                       \
  V(Random_setupSeed, 1)                                                       \
  V(Random_initialSeed, 0)                                                     \
  V(SecureRandom_getBytes, 1)                                                  \
  V(DateTime_currentTimeMicros, 0)                                             \
  V(DateTime_timeZoneName, 1)                                                  \
  V(DateTime_timeZoneOffsetInSeconds, 1)                                       \
  V(DateTime_localTimeZoneAdjustmentInSeconds, 0)                              \
  V(AssertionError_throwNew, 2)                                                \
  V(Async_rethrow, 2)                                                          \
  V(StackTrace_current, 0)                                                     \
  V(TypeError_throwNew, 5)                                                     \
  V(FallThroughError_throwNew, 1)                                              \
  V(AbstractClassInstantiationError_throwNew, 2)                               \
  V(Stopwatch_now, 0)                                                          \
  V(Stopwatch_frequency, 0)                                                    \
  V(Timeline_getIsolateNum, 0)                                                 \
  V(Timeline_getNextAsyncId, 0)                                                \
  V(Timeline_getTraceClock, 0)                                                 \
  V(Timeline_getThreadCpuClock, 0)                                             \
  V(Timeline_isDartStreamEnabled, 0)                                           \
  V(Timeline_reportCompleteEvent, 5)                                           \
  V(Timeline_reportInstantEvent, 4)                                            \
  V(Timeline_reportTaskEvent, 6)                                               \
  V(TypedData_Int8Array_new, 2)                                                \
  V(TypedData_Uint8Array_new, 2)                                               \
  V(TypedData_Uint8ClampedArray_new, 2)                                        \
  V(TypedData_Int16Array_new, 2)                                               \
  V(TypedData_Uint16Array_new, 2)                                              \
  V(TypedData_Int32Array_new, 2)                                               \
  V(TypedData_Uint32Array_new, 2)                                              \
  V(TypedData_Int64Array_new, 2)                                               \
  V(TypedData_Uint64Array_new, 2)                                              \
  V(TypedData_Float32Array_new, 2)                                             \
  V(TypedData_Float64Array_new, 2)                                             \
  V(TypedData_Float32x4Array_new, 2)                                           \
  V(TypedData_Int32x4Array_new, 2)                                             \
  V(TypedData_Float64x2Array_new, 2)                                           \
  V(ExternalTypedData_Int8Array_new, 2)                                        \
  V(ExternalTypedData_Uint8Array_new, 2)                                       \
  V(ExternalTypedData_Uint8ClampedArray_new, 2)                                \
  V(ExternalTypedData_Int16Array_new, 2)                                       \
  V(ExternalTypedData_Uint16Array_new, 2)                                      \
  V(ExternalTypedData_Int32Array_new, 2)                                       \
  V(ExternalTypedData_Uint32Array_new, 2)                                      \
  V(ExternalTypedData_Int64Array_new, 2)                                       \
  V(ExternalTypedData_Uint64Array_new, 2)                                      \
  V(ExternalTypedData_Float32Array_new, 2)                                     \
  V(ExternalTypedData_Float64Array_new, 2)                                     \
  V(ExternalTypedData_Float32x4Array_new, 2)                                   \
  V(ExternalTypedData_Int32x4Array_new, 2)                                     \
  V(ExternalTypedData_Float64x2Array_new, 2)                                   \
  V(TypedData_length, 1)                                                       \
  V(TypedData_setRange, 7)                                                     \
  V(TypedData_GetInt8, 2)                                                      \
  V(TypedData_SetInt8, 3)                                                      \
  V(TypedData_GetUint8, 2)                                                     \
  V(TypedData_SetUint8, 3)                                                     \
  V(TypedData_GetInt16, 2)                                                     \
  V(TypedData_SetInt16, 3)                                                     \
  V(TypedData_GetUint16, 2)                                                    \
  V(TypedData_SetUint16, 3)                                                    \
  V(TypedData_GetInt32, 2)                                                     \
  V(TypedData_SetInt32, 3)                                                     \
  V(TypedData_GetUint32, 2)                                                    \
  V(TypedData_SetUint32, 3)                                                    \
  V(TypedData_GetInt64, 2)                                                     \
  V(TypedData_SetInt64, 3)                                                     \
  V(TypedData_GetUint64, 2)                                                    \
  V(TypedData_SetUint64, 3)                                                    \
  V(TypedData_GetFloat32, 2)                                                   \
  V(TypedData_SetFloat32, 3)                                                   \
  V(TypedData_GetFloat64, 2)                                                   \
  V(TypedData_SetFloat64, 3)                                                   \
  V(TypedData_GetFloat32x4, 2)                                                 \
  V(TypedData_SetFloat32x4, 3)                                                 \
  V(TypedData_GetInt32x4, 2)                                                   \
  V(TypedData_SetInt32x4, 3)                                                   \
  V(TypedData_GetFloat64x2, 2)                                                 \
  V(TypedData_SetFloat64x2, 3)                                                 \
  V(ByteData_ToEndianInt16, 2)                                                 \
  V(ByteData_ToEndianUint16, 2)                                                \
  V(ByteData_ToEndianInt32, 2)                                                 \
  V(ByteData_ToEndianUint32, 2)                                                \
  V(ByteData_ToEndianInt64, 2)                                                 \
  V(ByteData_ToEndianUint64, 2)                                                \
  V(ByteData_ToEndianFloat32, 2)                                               \
  V(ByteData_ToEndianFloat64, 2)                                               \
  V(Float32x4_fromDoubles, 5)                                                  \
  V(Float32x4_splat, 2)                                                        \
  V(Float32x4_fromInt32x4Bits, 2)                                              \
  V(Float32x4_fromFloat64x2, 2)                                                \
  V(Float32x4_zero, 1)                                                         \
  V(Float32x4_add, 2)                                                          \
  V(Float32x4_negate, 1)                                                       \
  V(Float32x4_sub, 2)                                                          \
  V(Float32x4_mul, 2)                                                          \
  V(Float32x4_div, 2)                                                          \
  V(Float32x4_cmplt, 2)                                                        \
  V(Float32x4_cmplte, 2)                                                       \
  V(Float32x4_cmpgt, 2)                                                        \
  V(Float32x4_cmpgte, 2)                                                       \
  V(Float32x4_cmpequal, 2)                                                     \
  V(Float32x4_cmpnequal, 2)                                                    \
  V(Float32x4_scale, 2)                                                        \
  V(Float32x4_abs, 1)                                                          \
  V(Float32x4_clamp, 3)                                                        \
  V(Float32x4_getX, 1)                                                         \
  V(Float32x4_getY, 1)                                                         \
  V(Float32x4_getZ, 1)                                                         \
  V(Float32x4_getW, 1)                                                         \
  V(Float32x4_getSignMask, 1)                                                  \
  V(Float32x4_shuffle, 2)                                                      \
  V(Float32x4_shuffleMix, 3)                                                   \
  V(Float32x4_setX, 2)                                                         \
  V(Float32x4_setY, 2)                                                         \
  V(Float32x4_setZ, 2)                                                         \
  V(Float32x4_setW, 2)                                                         \
  V(Float32x4_min, 2)                                                          \
  V(Float32x4_max, 2)                                                          \
  V(Float32x4_sqrt, 1)                                                         \
  V(Float32x4_reciprocal, 1)                                                   \
  V(Float32x4_reciprocalSqrt, 1)                                               \
  V(Float64x2_fromDoubles, 3)                                                  \
  V(Float64x2_splat, 2)                                                        \
  V(Float64x2_zero, 1)                                                         \
  V(Float64x2_fromFloat32x4, 2)                                                \
  V(Float64x2_add, 2)                                                          \
  V(Float64x2_negate, 1)                                                       \
  V(Float64x2_sub, 2)                                                          \
  V(Float64x2_mul, 2)                                                          \
  V(Float64x2_div, 2)                                                          \
  V(Float64x2_scale, 2)                                                        \
  V(Float64x2_abs, 1)                                                          \
  V(Float64x2_clamp, 3)                                                        \
  V(Float64x2_getX, 1)                                                         \
  V(Float64x2_getY, 1)                                                         \
  V(Float64x2_getSignMask, 1)                                                  \
  V(Float64x2_setX, 2)                                                         \
  V(Float64x2_setY, 2)                                                         \
  V(Float64x2_min, 2)                                                          \
  V(Float64x2_max, 2)                                                          \
  V(Float64x2_sqrt, 1)                                                         \
  V(Int32x4_fromInts, 5)                                                       \
  V(Int32x4_fromBools, 5)                                                      \
  V(Int32x4_fromFloat32x4Bits, 2)                                              \
  V(Int32x4_or, 2)                                                             \
  V(Int32x4_and, 2)                                                            \
  V(Int32x4_xor, 2)                                                            \
  V(Int32x4_add, 2)                                                            \
  V(Int32x4_sub, 2)                                                            \
  V(Int32x4_getX, 1)                                                           \
  V(Int32x4_getY, 1)                                                           \
  V(Int32x4_getZ, 1)                                                           \
  V(Int32x4_getW, 1)                                                           \
  V(Int32x4_setX, 2)                                                           \
  V(Int32x4_setY, 2)                                                           \
  V(Int32x4_setZ, 2)                                                           \
  V(Int32x4_setW, 2)                                                           \
  V(Int32x4_getSignMask, 1)                                                    \
  V(Int32x4_shuffle, 2)                                                        \
  V(Int32x4_shuffleMix, 3)                                                     \
  V(Int32x4_getFlagX, 1)                                                       \
  V(Int32x4_getFlagY, 1)                                                       \
  V(Int32x4_getFlagZ, 1)                                                       \
  V(Int32x4_getFlagW, 1)                                                       \
  V(Int32x4_setFlagX, 2)                                                       \
  V(Int32x4_setFlagY, 2)                                                       \
  V(Int32x4_setFlagZ, 2)                                                       \
  V(Int32x4_setFlagW, 2)                                                       \
  V(Int32x4_select, 3)                                                         \
  V(Isolate_spawnFunction, 10)                                                 \
  V(Isolate_spawnUri, 12)                                                      \
  V(Isolate_getPortAndCapabilitiesOfCurrentIsolate, 0)                         \
  V(Isolate_getCurrentRootUriStr, 0)                                           \
  V(Isolate_sendOOB, 2)                                                        \
  V(GrowableList_allocate, 2)                                                  \
  V(GrowableList_getIndexed, 2)                                                \
  V(GrowableList_setIndexed, 3)                                                \
  V(GrowableList_getLength, 1)                                                 \
  V(GrowableList_getCapacity, 1)                                               \
  V(GrowableList_setLength, 2)                                                 \
  V(GrowableList_setData, 2)                                                   \
  V(Internal_makeListFixedLength, 1)                                           \
  V(Internal_makeFixedListUnmodifiable, 1)                                     \
  V(Internal_inquireIs64Bit, 0)                                                \
  V(LinkedHashMap_allocate, 1)                                                 \
  V(LinkedHashMap_getIndex, 1)                                                 \
  V(LinkedHashMap_setIndex, 2)                                                 \
  V(LinkedHashMap_getData, 1)                                                  \
  V(LinkedHashMap_setData, 2)                                                  \
  V(LinkedHashMap_getHashMask, 1)                                              \
  V(LinkedHashMap_setHashMask, 2)                                              \
  V(LinkedHashMap_getUsedData, 1)                                              \
  V(LinkedHashMap_setUsedData, 2)                                              \
  V(LinkedHashMap_getDeletedKeys, 1)                                           \
  V(LinkedHashMap_setDeletedKeys, 2)                                           \
  V(WeakProperty_new, 2)                                                       \
  V(WeakProperty_getKey, 1)                                                    \
  V(WeakProperty_getValue, 1)                                                  \
  V(WeakProperty_setValue, 2)                                                  \
  V(Uri_isWindowsPlatform, 0)                                                  \
  V(LibraryPrefix_load, 1)                                                     \
  V(LibraryPrefix_invalidateDependentCode, 1)                                  \
  V(LibraryPrefix_loadError, 1)                                                \
  V(LibraryPrefix_isLoaded, 1)                                                 \
  V(UserTag_new, 2)                                                            \
  V(UserTag_label, 1)                                                          \
  V(UserTag_defaultTag, 0)                                                     \
  V(UserTag_makeCurrent, 1)                                                    \
  V(Profiler_getCurrentTag, 0)                                                 \
  V(ClassID_getID, 1)                                                          \
  V(VMService_SendIsolateServiceMessage, 2)                                    \
  V(VMService_SendRootServiceMessage, 1)                                       \
  V(VMService_SendObjectRootServiceMessage, 1)                                 \
  V(VMService_OnStart, 0)                                                      \
  V(VMService_OnExit, 0)                                                       \
  V(VMService_OnServerAddressChange, 1)                                        \
  V(VMService_ListenStream, 1)                                                 \
  V(VMService_CancelStream, 1)                                                 \
  V(VMService_RequestAssets, 0)                                                \
  V(VMService_DecodeAssets, 1)                                                 \

// List of bootstrap native entry points used in the dart:mirror library.
#define MIRRORS_BOOTSTRAP_NATIVE_LIST(V)                                       \
  V(Mirrors_evalInLibraryWithPrivateKey, 2)                                    \
  V(Mirrors_makeLocalClassMirror, 1)                                           \
  V(Mirrors_makeLocalTypeMirror, 1)                                            \
  V(Mirrors_mangleName, 2)                                                     \
  V(MirrorReference_equals, 2)                                                 \
  V(MirrorSystem_libraries, 0)                                                 \
  V(MirrorSystem_isolate, 0)                                                   \
  V(InstanceMirror_invoke, 5)                                                  \
  V(InstanceMirror_invokeGetter, 3)                                            \
  V(InstanceMirror_invokeSetter, 4)                                            \
  V(InstanceMirror_computeType, 1)                                             \
  V(ClosureMirror_function, 1)                                                 \
  V(TypeMirror_subtypeTest, 2)                                                 \
  V(ClassMirror_libraryUri, 1)                                                 \
  V(ClassMirror_supertype, 1)                                                  \
  V(ClassMirror_supertype_instantiated, 1)                                     \
  V(ClassMirror_interfaces, 1)                                                 \
  V(ClassMirror_interfaces_instantiated, 1)                                    \
  V(ClassMirror_mixin, 1)                                                      \
  V(ClassMirror_mixin_instantiated, 2)                                         \
  V(ClassMirror_members, 3)                                                    \
  V(ClassMirror_constructors, 3)                                               \
  V(LibraryMirror_members, 2)                                                  \
  V(LibraryMirror_libraryDependencies, 2)                                      \
  V(ClassMirror_invoke, 5)                                                     \
  V(ClassMirror_invokeGetter, 3)                                               \
  V(ClassMirror_invokeSetter, 4)                                               \
  V(ClassMirror_invokeConstructor, 5)                                          \
  V(ClassMirror_type_variables, 1)                                             \
  V(ClassMirror_type_arguments, 1)                                             \
  V(LibraryMirror_fromPrefix, 1)                                               \
  V(LibraryMirror_invoke, 5)                                                   \
  V(LibraryMirror_invokeGetter, 3)                                             \
  V(LibraryMirror_invokeSetter, 4)                                             \
  V(TypeVariableMirror_owner, 1)                                               \
  V(TypeVariableMirror_upper_bound, 1)                                         \
  V(DeclarationMirror_location, 1)                                             \
  V(DeclarationMirror_metadata, 1)                                             \
  V(FunctionTypeMirror_call_method, 2)                                         \
  V(FunctionTypeMirror_parameters, 2)                                          \
  V(FunctionTypeMirror_return_type, 2)                                         \
  V(MethodMirror_owner, 2)                                                     \
  V(MethodMirror_parameters, 2)                                                \
  V(MethodMirror_return_type, 2)                                               \
  V(MethodMirror_source, 1)                                                    \
  V(ParameterMirror_type, 3)                                                   \
  V(TypedefMirror_referent, 1)                                                 \
  V(TypedefMirror_declaration, 1)                                              \
  V(VariableMirror_type, 2)                                                    \

class BootstrapNatives : public AllStatic {
 public:
  static Dart_NativeFunction Lookup(Dart_Handle name,
                                    int argument_count,
                                    bool* auto_setup_scope);

  static const uint8_t* Symbol(Dart_NativeFunction* nf);

#define DECLARE_BOOTSTRAP_NATIVE(name, ignored)                                \
  static void DN_##name(Dart_NativeArguments args);

  BOOTSTRAP_NATIVE_LIST(DECLARE_BOOTSTRAP_NATIVE)
#ifndef PRODUCT
  MIRRORS_BOOTSTRAP_NATIVE_LIST(DECLARE_BOOTSTRAP_NATIVE)
#endif

#undef DECLARE_BOOTSTRAP_NATIVE
};

}  // namespace dart

#endif  // VM_BOOTSTRAP_NATIVES_H_

// Copyright (c) 2017, the Dart project authors.  Please see the AUTHORS file
// for details. All rights reserved. Use of this source code is governed by a
// BSD-style license that can be found in the LICENSE file.

import 'package:front_end/src/fasta/type_inference/type_schema.dart';
import 'package:front_end/src/fasta/type_inference/type_schema_elimination.dart'
    as typeSchemaElimination;
import 'package:kernel/ast.dart';
import 'package:kernel/core_types.dart';
import 'package:test/test.dart';
import 'package:test_reflective_loader/test_reflective_loader.dart';

main() {
  defineReflectiveSuite(() {
    defineReflectiveTests(TypeSchemaEliminationTest);
  });
}

@reflectiveTest
class TypeSchemaEliminationTest {
  static const DartType unknownType = const UnknownType();

  CoreTypes coreTypes = new _MockCoreTypes();

  DartType get dynamicType => const DynamicType();

  DartType get objectType => coreTypes.objectLegacyRawType;

  DartType greatestClosure(DartType schema) {
    return typeSchemaElimination.greatestClosure(
        schema, dynamicType, const NullType());
  }

  DartType leastClosure(DartType schema) {
    return typeSchemaElimination.leastClosure(
        schema, dynamicType, const NullType());
  }

  void test_greatestClosure_contravariant() {
    expect(
        greatestClosure(new FunctionType(
                [unknownType], dynamicType, Nullability.legacy))
            .leakingDebugToString(),
        '(Null) →* dynamic');
    expect(
        greatestClosure(new FunctionType([], dynamicType, Nullability.legacy,
                namedParameters: [new NamedType('foo', unknownType)]))
            .leakingDebugToString(),
        '({foo: Null}) →* dynamic');
  }

  void test_greatestClosure_contravariant_contravariant() {
    expect(
        greatestClosure(new FunctionType([
          new FunctionType([unknownType], dynamicType, Nullability.legacy)
        ], dynamicType, Nullability.legacy))
            .leakingDebugToString(),
        '((dynamic) →* dynamic) →* dynamic');
  }

  void test_greatestClosure_covariant() {
    expect(
        greatestClosure(new FunctionType([], unknownType, Nullability.legacy))
            .leakingDebugToString(),
        '() →* dynamic');
    expect(
        greatestClosure(new InterfaceType(
                coreTypes.listClass, Nullability.legacy, [unknownType]))
            .leakingDebugToString(),
        'dart.core::List<dynamic>*');
  }

  void test_greatestClosure_function_multipleUnknown() {
    expect(
        greatestClosure(new FunctionType(
            [unknownType, unknownType], unknownType, Nullability.legacy,
            namedParameters: [
              new NamedType('a', unknownType),
              new NamedType('b', unknownType)
            ])).leakingDebugToString(),
        '(Null, Null, {a: Null, b: Null}) →* dynamic');
  }

  void test_greatestClosure_simple() {
    expect(greatestClosure(unknownType).leakingDebugToString(), 'dynamic');
  }

  void test_leastClosure_contravariant() {
    expect(
        leastClosure(new FunctionType(
                [unknownType], dynamicType, Nullability.legacy))
            .leakingDebugToString(),
        '(dynamic) →* dynamic');
    expect(
        leastClosure(new FunctionType([], dynamicType, Nullability.legacy,
                namedParameters: [new NamedType('foo', unknownType)]))
            .leakingDebugToString(),
        '({foo: dynamic}) →* dynamic');
  }

  void test_leastClosure_contravariant_contravariant() {
    expect(
        leastClosure(new FunctionType([
          new FunctionType([unknownType], dynamicType, Nullability.legacy)
        ], dynamicType, Nullability.legacy))
            .leakingDebugToString(),
        '((Null) →* dynamic) →* dynamic');
  }

  void test_leastClosure_covariant() {
    expect(
        leastClosure(new FunctionType([], unknownType, Nullability.legacy))
            .leakingDebugToString(),
        '() →* Null');
    expect(
        leastClosure(new InterfaceType(
                coreTypes.listClass, Nullability.legacy, [unknownType]))
            .leakingDebugToString(),
        'dart.core::List<Null>*');
  }

  void test_leastClosure_function_multipleUnknown() {
    expect(
        leastClosure(new FunctionType(
            [unknownType, unknownType], unknownType, Nullability.legacy,
            namedParameters: [
              new NamedType('a', unknownType),
              new NamedType('b', unknownType)
            ])).leakingDebugToString(),
        '(dynamic, dynamic, {a: dynamic, b: dynamic}) →* Null');
  }

  void test_leastClosure_simple() {
    expect(leastClosure(unknownType).leakingDebugToString(), 'Null');
  }
}

class _MockCoreTypes implements CoreTypes {
  @override
  final Class listClass = new Class(name: 'List');

  @override
  final Class objectClass = new Class(name: 'Object');

  _MockCoreTypes() {
    new Library(Uri.parse('dart:core'),
        name: 'dart.core', classes: [listClass, objectClass]);
  }

  noSuchMethod(Invocation invocation) => super.noSuchMethod(invocation);
}

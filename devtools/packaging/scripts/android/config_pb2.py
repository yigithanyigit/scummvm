# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: config.proto
"""Generated protocol buffer code."""
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='config.proto',
  package='android.bundle',
  syntax='proto3',
  serialized_options=b'\n\022com.android.bundle',
  create_key=_descriptor._internal_create_key,
  serialized_pb=b'\n\x0c\x63onfig.proto\x12\x0e\x61ndroid.bundle\"\x91\x04\n\x0c\x42undleConfig\x12.\n\nbundletool\x18\x01 \x01(\x0b\x32\x1a.android.bundle.Bundletool\x12\x34\n\roptimizations\x18\x02 \x01(\x0b\x32\x1d.android.bundle.Optimizations\x12\x30\n\x0b\x63ompression\x18\x03 \x01(\x0b\x32\x1b.android.bundle.Compression\x12\x39\n\x10master_resources\x18\x04 \x01(\x0b\x32\x1f.android.bundle.MasterResources\x12/\n\x0b\x61pex_config\x18\x05 \x01(\x0b\x32\x1a.android.bundle.ApexConfig\x12O\n\x1cunsigned_embedded_apk_config\x18\x06 \x03(\x0b\x32).android.bundle.UnsignedEmbeddedApkConfig\x12@\n\x14\x61sset_modules_config\x18\x07 \x01(\x0b\x32\".android.bundle.AssetModulesConfig\x12\x35\n\x04type\x18\x08 \x01(\x0e\x32\'.android.bundle.BundleConfig.BundleType\"3\n\nBundleType\x12\x0b\n\x07REGULAR\x10\x00\x12\x08\n\x04\x41PEX\x10\x01\x12\x0e\n\nASSET_ONLY\x10\x02\"#\n\nBundletool\x12\x0f\n\x07version\x18\x02 \x01(\tJ\x04\x08\x01\x10\x02\"\xe0\x01\n\x0b\x43ompression\x12\x19\n\x11uncompressed_glob\x18\x01 \x03(\t\x12i\n-install_time_asset_module_default_compression\x18\x02 \x01(\x0e\x32\x32.android.bundle.Compression.AssetModuleCompression\"K\n\x16\x41ssetModuleCompression\x12\x0f\n\x0bUNSPECIFIED\x10\x00\x12\x10\n\x0cUNCOMPRESSED\x10\x01\x12\x0e\n\nCOMPRESSED\x10\x02\"?\n\x0fMasterResources\x12\x14\n\x0cresource_ids\x18\x01 \x03(\x05\x12\x16\n\x0eresource_names\x18\x02 \x03(\t\"\x93\x02\n\rOptimizations\x12\x33\n\rsplits_config\x18\x01 \x01(\x0b\x32\x1c.android.bundle.SplitsConfig\x12N\n\x1buncompress_native_libraries\x18\x02 \x01(\x0b\x32).android.bundle.UncompressNativeLibraries\x12@\n\x14uncompress_dex_files\x18\x03 \x01(\x0b\x32\".android.bundle.UncompressDexFiles\x12;\n\x11standalone_config\x18\x04 \x01(\x0b\x32 .android.bundle.StandaloneConfig\",\n\x19UncompressNativeLibraries\x12\x0f\n\x07\x65nabled\x18\x01 \x01(\x08\"%\n\x12UncompressDexFiles\x12\x0f\n\x07\x65nabled\x18\x01 \x01(\x08\"G\n\x0cSplitsConfig\x12\x37\n\x0fsplit_dimension\x18\x01 \x03(\x0b\x32\x1e.android.bundle.SplitDimension\"\xfa\x01\n\x10StandaloneConfig\x12\x37\n\x0fsplit_dimension\x18\x01 \x03(\x0b\x32\x1e.android.bundle.SplitDimension\x12\x1e\n\x16strip_64_bit_libraries\x18\x02 \x01(\x08\x12Q\n\x14\x64\x65x_merging_strategy\x18\x03 \x01(\x0e\x32\x33.android.bundle.StandaloneConfig.DexMergingStrategy\":\n\x12\x44\x65xMergingStrategy\x12\x13\n\x0fMERGE_IF_NEEDED\x10\x00\x12\x0f\n\x0bNEVER_MERGE\x10\x01\"\x8c\x02\n\x0eSplitDimension\x12\x33\n\x05value\x18\x01 \x01(\x0e\x32$.android.bundle.SplitDimension.Value\x12\x0e\n\x06negate\x18\x02 \x01(\x08\x12\x39\n\x10suffix_stripping\x18\x03 \x01(\x0b\x32\x1f.android.bundle.SuffixStripping\"z\n\x05Value\x12\x15\n\x11UNSPECIFIED_VALUE\x10\x00\x12\x07\n\x03\x41\x42I\x10\x01\x12\x12\n\x0eSCREEN_DENSITY\x10\x02\x12\x0c\n\x08LANGUAGE\x10\x03\x12\x1e\n\x1aTEXTURE_COMPRESSION_FORMAT\x10\x04\x12\x0f\n\x0b\x44\x45VICE_TIER\x10\x06\":\n\x0fSuffixStripping\x12\x0f\n\x07\x65nabled\x18\x01 \x01(\x08\x12\x16\n\x0e\x64\x65\x66\x61ult_suffix\x18\x02 \x01(\t\"U\n\nApexConfig\x12G\n\x18\x61pex_embedded_apk_config\x18\x01 \x03(\x0b\x32%.android.bundle.ApexEmbeddedApkConfig\";\n\x15\x41pexEmbeddedApkConfig\x12\x14\n\x0cpackage_name\x18\x01 \x01(\t\x12\x0c\n\x04path\x18\x02 \x01(\t\")\n\x19UnsignedEmbeddedApkConfig\x12\x0c\n\x04path\x18\x01 \x01(\t\"D\n\x12\x41ssetModulesConfig\x12\x13\n\x0b\x61pp_version\x18\x01 \x03(\x03\x12\x19\n\x11\x61sset_version_tag\x18\x02 \x01(\tB\x14\n\x12\x63om.android.bundleb\x06proto3'
)



_BUNDLECONFIG_BUNDLETYPE = _descriptor.EnumDescriptor(
  name='BundleType',
  full_name='android.bundle.BundleConfig.BundleType',
  filename=None,
  file=DESCRIPTOR,
  create_key=_descriptor._internal_create_key,
  values=[
    _descriptor.EnumValueDescriptor(
      name='REGULAR', index=0, number=0,
      serialized_options=None,
      type=None,
      create_key=_descriptor._internal_create_key),
    _descriptor.EnumValueDescriptor(
      name='APEX', index=1, number=1,
      serialized_options=None,
      type=None,
      create_key=_descriptor._internal_create_key),
    _descriptor.EnumValueDescriptor(
      name='ASSET_ONLY', index=2, number=2,
      serialized_options=None,
      type=None,
      create_key=_descriptor._internal_create_key),
  ],
  containing_type=None,
  serialized_options=None,
  serialized_start=511,
  serialized_end=562,
)
_sym_db.RegisterEnumDescriptor(_BUNDLECONFIG_BUNDLETYPE)

_COMPRESSION_ASSETMODULECOMPRESSION = _descriptor.EnumDescriptor(
  name='AssetModuleCompression',
  full_name='android.bundle.Compression.AssetModuleCompression',
  filename=None,
  file=DESCRIPTOR,
  create_key=_descriptor._internal_create_key,
  values=[
    _descriptor.EnumValueDescriptor(
      name='UNSPECIFIED', index=0, number=0,
      serialized_options=None,
      type=None,
      create_key=_descriptor._internal_create_key),
    _descriptor.EnumValueDescriptor(
      name='UNCOMPRESSED', index=1, number=1,
      serialized_options=None,
      type=None,
      create_key=_descriptor._internal_create_key),
    _descriptor.EnumValueDescriptor(
      name='COMPRESSED', index=2, number=2,
      serialized_options=None,
      type=None,
      create_key=_descriptor._internal_create_key),
  ],
  containing_type=None,
  serialized_options=None,
  serialized_start=751,
  serialized_end=826,
)
_sym_db.RegisterEnumDescriptor(_COMPRESSION_ASSETMODULECOMPRESSION)

_STANDALONECONFIG_DEXMERGINGSTRATEGY = _descriptor.EnumDescriptor(
  name='DexMergingStrategy',
  full_name='android.bundle.StandaloneConfig.DexMergingStrategy',
  filename=None,
  file=DESCRIPTOR,
  create_key=_descriptor._internal_create_key,
  values=[
    _descriptor.EnumValueDescriptor(
      name='MERGE_IF_NEEDED', index=0, number=0,
      serialized_options=None,
      type=None,
      create_key=_descriptor._internal_create_key),
    _descriptor.EnumValueDescriptor(
      name='NEVER_MERGE', index=1, number=1,
      serialized_options=None,
      type=None,
      create_key=_descriptor._internal_create_key),
  ],
  containing_type=None,
  serialized_options=None,
  serialized_start=1522,
  serialized_end=1580,
)
_sym_db.RegisterEnumDescriptor(_STANDALONECONFIG_DEXMERGINGSTRATEGY)

_SPLITDIMENSION_VALUE = _descriptor.EnumDescriptor(
  name='Value',
  full_name='android.bundle.SplitDimension.Value',
  filename=None,
  file=DESCRIPTOR,
  create_key=_descriptor._internal_create_key,
  values=[
    _descriptor.EnumValueDescriptor(
      name='UNSPECIFIED_VALUE', index=0, number=0,
      serialized_options=None,
      type=None,
      create_key=_descriptor._internal_create_key),
    _descriptor.EnumValueDescriptor(
      name='ABI', index=1, number=1,
      serialized_options=None,
      type=None,
      create_key=_descriptor._internal_create_key),
    _descriptor.EnumValueDescriptor(
      name='SCREEN_DENSITY', index=2, number=2,
      serialized_options=None,
      type=None,
      create_key=_descriptor._internal_create_key),
    _descriptor.EnumValueDescriptor(
      name='LANGUAGE', index=3, number=3,
      serialized_options=None,
      type=None,
      create_key=_descriptor._internal_create_key),
    _descriptor.EnumValueDescriptor(
      name='TEXTURE_COMPRESSION_FORMAT', index=4, number=4,
      serialized_options=None,
      type=None,
      create_key=_descriptor._internal_create_key),
    _descriptor.EnumValueDescriptor(
      name='DEVICE_TIER', index=5, number=6,
      serialized_options=None,
      type=None,
      create_key=_descriptor._internal_create_key),
  ],
  containing_type=None,
  serialized_options=None,
  serialized_start=1729,
  serialized_end=1851,
)
_sym_db.RegisterEnumDescriptor(_SPLITDIMENSION_VALUE)


_BUNDLECONFIG = _descriptor.Descriptor(
  name='BundleConfig',
  full_name='android.bundle.BundleConfig',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='bundletool', full_name='android.bundle.BundleConfig.bundletool', index=0,
      number=1, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='optimizations', full_name='android.bundle.BundleConfig.optimizations', index=1,
      number=2, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='compression', full_name='android.bundle.BundleConfig.compression', index=2,
      number=3, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='master_resources', full_name='android.bundle.BundleConfig.master_resources', index=3,
      number=4, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='apex_config', full_name='android.bundle.BundleConfig.apex_config', index=4,
      number=5, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='unsigned_embedded_apk_config', full_name='android.bundle.BundleConfig.unsigned_embedded_apk_config', index=5,
      number=6, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='asset_modules_config', full_name='android.bundle.BundleConfig.asset_modules_config', index=6,
      number=7, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='type', full_name='android.bundle.BundleConfig.type', index=7,
      number=8, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
    _BUNDLECONFIG_BUNDLETYPE,
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=33,
  serialized_end=562,
)


_BUNDLETOOL = _descriptor.Descriptor(
  name='Bundletool',
  full_name='android.bundle.Bundletool',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='version', full_name='android.bundle.Bundletool.version', index=0,
      number=2, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=564,
  serialized_end=599,
)


_COMPRESSION = _descriptor.Descriptor(
  name='Compression',
  full_name='android.bundle.Compression',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='uncompressed_glob', full_name='android.bundle.Compression.uncompressed_glob', index=0,
      number=1, type=9, cpp_type=9, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='install_time_asset_module_default_compression', full_name='android.bundle.Compression.install_time_asset_module_default_compression', index=1,
      number=2, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
    _COMPRESSION_ASSETMODULECOMPRESSION,
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=602,
  serialized_end=826,
)


_MASTERRESOURCES = _descriptor.Descriptor(
  name='MasterResources',
  full_name='android.bundle.MasterResources',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='resource_ids', full_name='android.bundle.MasterResources.resource_ids', index=0,
      number=1, type=5, cpp_type=1, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='resource_names', full_name='android.bundle.MasterResources.resource_names', index=1,
      number=2, type=9, cpp_type=9, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=828,
  serialized_end=891,
)


_OPTIMIZATIONS = _descriptor.Descriptor(
  name='Optimizations',
  full_name='android.bundle.Optimizations',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='splits_config', full_name='android.bundle.Optimizations.splits_config', index=0,
      number=1, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='uncompress_native_libraries', full_name='android.bundle.Optimizations.uncompress_native_libraries', index=1,
      number=2, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='uncompress_dex_files', full_name='android.bundle.Optimizations.uncompress_dex_files', index=2,
      number=3, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='standalone_config', full_name='android.bundle.Optimizations.standalone_config', index=3,
      number=4, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=894,
  serialized_end=1169,
)


_UNCOMPRESSNATIVELIBRARIES = _descriptor.Descriptor(
  name='UncompressNativeLibraries',
  full_name='android.bundle.UncompressNativeLibraries',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='enabled', full_name='android.bundle.UncompressNativeLibraries.enabled', index=0,
      number=1, type=8, cpp_type=7, label=1,
      has_default_value=False, default_value=False,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=1171,
  serialized_end=1215,
)


_UNCOMPRESSDEXFILES = _descriptor.Descriptor(
  name='UncompressDexFiles',
  full_name='android.bundle.UncompressDexFiles',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='enabled', full_name='android.bundle.UncompressDexFiles.enabled', index=0,
      number=1, type=8, cpp_type=7, label=1,
      has_default_value=False, default_value=False,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=1217,
  serialized_end=1254,
)


_SPLITSCONFIG = _descriptor.Descriptor(
  name='SplitsConfig',
  full_name='android.bundle.SplitsConfig',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='split_dimension', full_name='android.bundle.SplitsConfig.split_dimension', index=0,
      number=1, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=1256,
  serialized_end=1327,
)


_STANDALONECONFIG = _descriptor.Descriptor(
  name='StandaloneConfig',
  full_name='android.bundle.StandaloneConfig',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='split_dimension', full_name='android.bundle.StandaloneConfig.split_dimension', index=0,
      number=1, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='strip_64_bit_libraries', full_name='android.bundle.StandaloneConfig.strip_64_bit_libraries', index=1,
      number=2, type=8, cpp_type=7, label=1,
      has_default_value=False, default_value=False,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='dex_merging_strategy', full_name='android.bundle.StandaloneConfig.dex_merging_strategy', index=2,
      number=3, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
    _STANDALONECONFIG_DEXMERGINGSTRATEGY,
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=1330,
  serialized_end=1580,
)


_SPLITDIMENSION = _descriptor.Descriptor(
  name='SplitDimension',
  full_name='android.bundle.SplitDimension',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='value', full_name='android.bundle.SplitDimension.value', index=0,
      number=1, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='negate', full_name='android.bundle.SplitDimension.negate', index=1,
      number=2, type=8, cpp_type=7, label=1,
      has_default_value=False, default_value=False,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='suffix_stripping', full_name='android.bundle.SplitDimension.suffix_stripping', index=2,
      number=3, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
    _SPLITDIMENSION_VALUE,
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=1583,
  serialized_end=1851,
)


_SUFFIXSTRIPPING = _descriptor.Descriptor(
  name='SuffixStripping',
  full_name='android.bundle.SuffixStripping',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='enabled', full_name='android.bundle.SuffixStripping.enabled', index=0,
      number=1, type=8, cpp_type=7, label=1,
      has_default_value=False, default_value=False,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='default_suffix', full_name='android.bundle.SuffixStripping.default_suffix', index=1,
      number=2, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=1853,
  serialized_end=1911,
)


_APEXCONFIG = _descriptor.Descriptor(
  name='ApexConfig',
  full_name='android.bundle.ApexConfig',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='apex_embedded_apk_config', full_name='android.bundle.ApexConfig.apex_embedded_apk_config', index=0,
      number=1, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=1913,
  serialized_end=1998,
)


_APEXEMBEDDEDAPKCONFIG = _descriptor.Descriptor(
  name='ApexEmbeddedApkConfig',
  full_name='android.bundle.ApexEmbeddedApkConfig',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='package_name', full_name='android.bundle.ApexEmbeddedApkConfig.package_name', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='path', full_name='android.bundle.ApexEmbeddedApkConfig.path', index=1,
      number=2, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=2000,
  serialized_end=2059,
)


_UNSIGNEDEMBEDDEDAPKCONFIG = _descriptor.Descriptor(
  name='UnsignedEmbeddedApkConfig',
  full_name='android.bundle.UnsignedEmbeddedApkConfig',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='path', full_name='android.bundle.UnsignedEmbeddedApkConfig.path', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=2061,
  serialized_end=2102,
)


_ASSETMODULESCONFIG = _descriptor.Descriptor(
  name='AssetModulesConfig',
  full_name='android.bundle.AssetModulesConfig',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='app_version', full_name='android.bundle.AssetModulesConfig.app_version', index=0,
      number=1, type=3, cpp_type=2, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='asset_version_tag', full_name='android.bundle.AssetModulesConfig.asset_version_tag', index=1,
      number=2, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=2104,
  serialized_end=2172,
)

_BUNDLECONFIG.fields_by_name['bundletool'].message_type = _BUNDLETOOL
_BUNDLECONFIG.fields_by_name['optimizations'].message_type = _OPTIMIZATIONS
_BUNDLECONFIG.fields_by_name['compression'].message_type = _COMPRESSION
_BUNDLECONFIG.fields_by_name['master_resources'].message_type = _MASTERRESOURCES
_BUNDLECONFIG.fields_by_name['apex_config'].message_type = _APEXCONFIG
_BUNDLECONFIG.fields_by_name['unsigned_embedded_apk_config'].message_type = _UNSIGNEDEMBEDDEDAPKCONFIG
_BUNDLECONFIG.fields_by_name['asset_modules_config'].message_type = _ASSETMODULESCONFIG
_BUNDLECONFIG.fields_by_name['type'].enum_type = _BUNDLECONFIG_BUNDLETYPE
_BUNDLECONFIG_BUNDLETYPE.containing_type = _BUNDLECONFIG
_COMPRESSION.fields_by_name['install_time_asset_module_default_compression'].enum_type = _COMPRESSION_ASSETMODULECOMPRESSION
_COMPRESSION_ASSETMODULECOMPRESSION.containing_type = _COMPRESSION
_OPTIMIZATIONS.fields_by_name['splits_config'].message_type = _SPLITSCONFIG
_OPTIMIZATIONS.fields_by_name['uncompress_native_libraries'].message_type = _UNCOMPRESSNATIVELIBRARIES
_OPTIMIZATIONS.fields_by_name['uncompress_dex_files'].message_type = _UNCOMPRESSDEXFILES
_OPTIMIZATIONS.fields_by_name['standalone_config'].message_type = _STANDALONECONFIG
_SPLITSCONFIG.fields_by_name['split_dimension'].message_type = _SPLITDIMENSION
_STANDALONECONFIG.fields_by_name['split_dimension'].message_type = _SPLITDIMENSION
_STANDALONECONFIG.fields_by_name['dex_merging_strategy'].enum_type = _STANDALONECONFIG_DEXMERGINGSTRATEGY
_STANDALONECONFIG_DEXMERGINGSTRATEGY.containing_type = _STANDALONECONFIG
_SPLITDIMENSION.fields_by_name['value'].enum_type = _SPLITDIMENSION_VALUE
_SPLITDIMENSION.fields_by_name['suffix_stripping'].message_type = _SUFFIXSTRIPPING
_SPLITDIMENSION_VALUE.containing_type = _SPLITDIMENSION
_APEXCONFIG.fields_by_name['apex_embedded_apk_config'].message_type = _APEXEMBEDDEDAPKCONFIG
DESCRIPTOR.message_types_by_name['BundleConfig'] = _BUNDLECONFIG
DESCRIPTOR.message_types_by_name['Bundletool'] = _BUNDLETOOL
DESCRIPTOR.message_types_by_name['Compression'] = _COMPRESSION
DESCRIPTOR.message_types_by_name['MasterResources'] = _MASTERRESOURCES
DESCRIPTOR.message_types_by_name['Optimizations'] = _OPTIMIZATIONS
DESCRIPTOR.message_types_by_name['UncompressNativeLibraries'] = _UNCOMPRESSNATIVELIBRARIES
DESCRIPTOR.message_types_by_name['UncompressDexFiles'] = _UNCOMPRESSDEXFILES
DESCRIPTOR.message_types_by_name['SplitsConfig'] = _SPLITSCONFIG
DESCRIPTOR.message_types_by_name['StandaloneConfig'] = _STANDALONECONFIG
DESCRIPTOR.message_types_by_name['SplitDimension'] = _SPLITDIMENSION
DESCRIPTOR.message_types_by_name['SuffixStripping'] = _SUFFIXSTRIPPING
DESCRIPTOR.message_types_by_name['ApexConfig'] = _APEXCONFIG
DESCRIPTOR.message_types_by_name['ApexEmbeddedApkConfig'] = _APEXEMBEDDEDAPKCONFIG
DESCRIPTOR.message_types_by_name['UnsignedEmbeddedApkConfig'] = _UNSIGNEDEMBEDDEDAPKCONFIG
DESCRIPTOR.message_types_by_name['AssetModulesConfig'] = _ASSETMODULESCONFIG
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

BundleConfig = _reflection.GeneratedProtocolMessageType('BundleConfig', (_message.Message,), {
  'DESCRIPTOR' : _BUNDLECONFIG,
  '__module__' : 'config_pb2'
  # @@protoc_insertion_point(class_scope:android.bundle.BundleConfig)
  })
_sym_db.RegisterMessage(BundleConfig)

Bundletool = _reflection.GeneratedProtocolMessageType('Bundletool', (_message.Message,), {
  'DESCRIPTOR' : _BUNDLETOOL,
  '__module__' : 'config_pb2'
  # @@protoc_insertion_point(class_scope:android.bundle.Bundletool)
  })
_sym_db.RegisterMessage(Bundletool)

Compression = _reflection.GeneratedProtocolMessageType('Compression', (_message.Message,), {
  'DESCRIPTOR' : _COMPRESSION,
  '__module__' : 'config_pb2'
  # @@protoc_insertion_point(class_scope:android.bundle.Compression)
  })
_sym_db.RegisterMessage(Compression)

MasterResources = _reflection.GeneratedProtocolMessageType('MasterResources', (_message.Message,), {
  'DESCRIPTOR' : _MASTERRESOURCES,
  '__module__' : 'config_pb2'
  # @@protoc_insertion_point(class_scope:android.bundle.MasterResources)
  })
_sym_db.RegisterMessage(MasterResources)

Optimizations = _reflection.GeneratedProtocolMessageType('Optimizations', (_message.Message,), {
  'DESCRIPTOR' : _OPTIMIZATIONS,
  '__module__' : 'config_pb2'
  # @@protoc_insertion_point(class_scope:android.bundle.Optimizations)
  })
_sym_db.RegisterMessage(Optimizations)

UncompressNativeLibraries = _reflection.GeneratedProtocolMessageType('UncompressNativeLibraries', (_message.Message,), {
  'DESCRIPTOR' : _UNCOMPRESSNATIVELIBRARIES,
  '__module__' : 'config_pb2'
  # @@protoc_insertion_point(class_scope:android.bundle.UncompressNativeLibraries)
  })
_sym_db.RegisterMessage(UncompressNativeLibraries)

UncompressDexFiles = _reflection.GeneratedProtocolMessageType('UncompressDexFiles', (_message.Message,), {
  'DESCRIPTOR' : _UNCOMPRESSDEXFILES,
  '__module__' : 'config_pb2'
  # @@protoc_insertion_point(class_scope:android.bundle.UncompressDexFiles)
  })
_sym_db.RegisterMessage(UncompressDexFiles)

SplitsConfig = _reflection.GeneratedProtocolMessageType('SplitsConfig', (_message.Message,), {
  'DESCRIPTOR' : _SPLITSCONFIG,
  '__module__' : 'config_pb2'
  # @@protoc_insertion_point(class_scope:android.bundle.SplitsConfig)
  })
_sym_db.RegisterMessage(SplitsConfig)

StandaloneConfig = _reflection.GeneratedProtocolMessageType('StandaloneConfig', (_message.Message,), {
  'DESCRIPTOR' : _STANDALONECONFIG,
  '__module__' : 'config_pb2'
  # @@protoc_insertion_point(class_scope:android.bundle.StandaloneConfig)
  })
_sym_db.RegisterMessage(StandaloneConfig)

SplitDimension = _reflection.GeneratedProtocolMessageType('SplitDimension', (_message.Message,), {
  'DESCRIPTOR' : _SPLITDIMENSION,
  '__module__' : 'config_pb2'
  # @@protoc_insertion_point(class_scope:android.bundle.SplitDimension)
  })
_sym_db.RegisterMessage(SplitDimension)

SuffixStripping = _reflection.GeneratedProtocolMessageType('SuffixStripping', (_message.Message,), {
  'DESCRIPTOR' : _SUFFIXSTRIPPING,
  '__module__' : 'config_pb2'
  # @@protoc_insertion_point(class_scope:android.bundle.SuffixStripping)
  })
_sym_db.RegisterMessage(SuffixStripping)

ApexConfig = _reflection.GeneratedProtocolMessageType('ApexConfig', (_message.Message,), {
  'DESCRIPTOR' : _APEXCONFIG,
  '__module__' : 'config_pb2'
  # @@protoc_insertion_point(class_scope:android.bundle.ApexConfig)
  })
_sym_db.RegisterMessage(ApexConfig)

ApexEmbeddedApkConfig = _reflection.GeneratedProtocolMessageType('ApexEmbeddedApkConfig', (_message.Message,), {
  'DESCRIPTOR' : _APEXEMBEDDEDAPKCONFIG,
  '__module__' : 'config_pb2'
  # @@protoc_insertion_point(class_scope:android.bundle.ApexEmbeddedApkConfig)
  })
_sym_db.RegisterMessage(ApexEmbeddedApkConfig)

UnsignedEmbeddedApkConfig = _reflection.GeneratedProtocolMessageType('UnsignedEmbeddedApkConfig', (_message.Message,), {
  'DESCRIPTOR' : _UNSIGNEDEMBEDDEDAPKCONFIG,
  '__module__' : 'config_pb2'
  # @@protoc_insertion_point(class_scope:android.bundle.UnsignedEmbeddedApkConfig)
  })
_sym_db.RegisterMessage(UnsignedEmbeddedApkConfig)

AssetModulesConfig = _reflection.GeneratedProtocolMessageType('AssetModulesConfig', (_message.Message,), {
  'DESCRIPTOR' : _ASSETMODULESCONFIG,
  '__module__' : 'config_pb2'
  # @@protoc_insertion_point(class_scope:android.bundle.AssetModulesConfig)
  })
_sym_db.RegisterMessage(AssetModulesConfig)


DESCRIPTOR._options = None
# @@protoc_insertion_point(module_scope)

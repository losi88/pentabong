// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ari.proto

#include "ari.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

namespace ari {
PROTOBUF_CONSTEXPR AriConfig::AriConfig(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.port_)*/0
  , /*decltype(_impl_.acceptcount_)*/0
  , /*decltype(_impl_.workercount_)*/0
  , /*decltype(_impl_.ipversion_)*/0
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct AriConfigDefaultTypeInternal {
  PROTOBUF_CONSTEXPR AriConfigDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~AriConfigDefaultTypeInternal() {}
  union {
    AriConfig _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 AriConfigDefaultTypeInternal _AriConfig_default_instance_;
}  // namespace ari
static ::_pb::Metadata file_level_metadata_ari_2eproto[1];
static const ::_pb::EnumDescriptor* file_level_enum_descriptors_ari_2eproto[1];
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_ari_2eproto = nullptr;

const uint32_t TableStruct_ari_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::ari::AriConfig, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::ari::AriConfig, _impl_.port_),
  PROTOBUF_FIELD_OFFSET(::ari::AriConfig, _impl_.acceptcount_),
  PROTOBUF_FIELD_OFFSET(::ari::AriConfig, _impl_.workercount_),
  PROTOBUF_FIELD_OFFSET(::ari::AriConfig, _impl_.ipversion_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::ari::AriConfig)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::ari::_AriConfig_default_instance_._instance,
};

const char descriptor_table_protodef_ari_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\tari.proto\022\003ari\"\231\001\n\tAriConfig\022\014\n\004port\030\001"
  " \001(\005\022\023\n\013acceptCount\030\002 \001(\005\022\023\n\013workerCount"
  "\030\003 \001(\005\022,\n\tipVersion\030\004 \001(\0162\031.ari.AriConfi"
  "g.IP_VERSION\"&\n\nIP_VERSION\022\010\n\004NONE\020\000\022\006\n\002"
  "V4\020\001\022\006\n\002V6\020\002b\006proto3"
  ;
static ::_pbi::once_flag descriptor_table_ari_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_ari_2eproto = {
    false, false, 180, descriptor_table_protodef_ari_2eproto,
    "ari.proto",
    &descriptor_table_ari_2eproto_once, nullptr, 0, 1,
    schemas, file_default_instances, TableStruct_ari_2eproto::offsets,
    file_level_metadata_ari_2eproto, file_level_enum_descriptors_ari_2eproto,
    file_level_service_descriptors_ari_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_ari_2eproto_getter() {
  return &descriptor_table_ari_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_ari_2eproto(&descriptor_table_ari_2eproto);
namespace ari {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* AriConfig_IP_VERSION_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_ari_2eproto);
  return file_level_enum_descriptors_ari_2eproto[0];
}
bool AriConfig_IP_VERSION_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}

#if (__cplusplus < 201703) && (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))
constexpr AriConfig_IP_VERSION AriConfig::NONE;
constexpr AriConfig_IP_VERSION AriConfig::V4;
constexpr AriConfig_IP_VERSION AriConfig::V6;
constexpr AriConfig_IP_VERSION AriConfig::IP_VERSION_MIN;
constexpr AriConfig_IP_VERSION AriConfig::IP_VERSION_MAX;
constexpr int AriConfig::IP_VERSION_ARRAYSIZE;
#endif  // (__cplusplus < 201703) && (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))

// ===================================================================

class AriConfig::_Internal {
 public:
};

AriConfig::AriConfig(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:ari.AriConfig)
}
AriConfig::AriConfig(const AriConfig& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  AriConfig* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.port_){}
    , decltype(_impl_.acceptcount_){}
    , decltype(_impl_.workercount_){}
    , decltype(_impl_.ipversion_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&_impl_.port_, &from._impl_.port_,
    static_cast<size_t>(reinterpret_cast<char*>(&_impl_.ipversion_) -
    reinterpret_cast<char*>(&_impl_.port_)) + sizeof(_impl_.ipversion_));
  // @@protoc_insertion_point(copy_constructor:ari.AriConfig)
}

inline void AriConfig::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.port_){0}
    , decltype(_impl_.acceptcount_){0}
    , decltype(_impl_.workercount_){0}
    , decltype(_impl_.ipversion_){0}
    , /*decltype(_impl_._cached_size_)*/{}
  };
}

AriConfig::~AriConfig() {
  // @@protoc_insertion_point(destructor:ari.AriConfig)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void AriConfig::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void AriConfig::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void AriConfig::Clear() {
// @@protoc_insertion_point(message_clear_start:ari.AriConfig)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&_impl_.port_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&_impl_.ipversion_) -
      reinterpret_cast<char*>(&_impl_.port_)) + sizeof(_impl_.ipversion_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* AriConfig::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // int32 port = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          _impl_.port_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // int32 acceptCount = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          _impl_.acceptcount_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // int32 workerCount = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 24)) {
          _impl_.workercount_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // .ari.AriConfig.IP_VERSION ipVersion = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 32)) {
          uint64_t val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_ipversion(static_cast<::ari::AriConfig_IP_VERSION>(val));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* AriConfig::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:ari.AriConfig)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 port = 1;
  if (this->_internal_port() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(1, this->_internal_port(), target);
  }

  // int32 acceptCount = 2;
  if (this->_internal_acceptcount() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(2, this->_internal_acceptcount(), target);
  }

  // int32 workerCount = 3;
  if (this->_internal_workercount() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(3, this->_internal_workercount(), target);
  }

  // .ari.AriConfig.IP_VERSION ipVersion = 4;
  if (this->_internal_ipversion() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
      4, this->_internal_ipversion(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:ari.AriConfig)
  return target;
}

size_t AriConfig::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:ari.AriConfig)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // int32 port = 1;
  if (this->_internal_port() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_port());
  }

  // int32 acceptCount = 2;
  if (this->_internal_acceptcount() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_acceptcount());
  }

  // int32 workerCount = 3;
  if (this->_internal_workercount() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_workercount());
  }

  // .ari.AriConfig.IP_VERSION ipVersion = 4;
  if (this->_internal_ipversion() != 0) {
    total_size += 1 +
      ::_pbi::WireFormatLite::EnumSize(this->_internal_ipversion());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData AriConfig::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    AriConfig::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*AriConfig::GetClassData() const { return &_class_data_; }


void AriConfig::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<AriConfig*>(&to_msg);
  auto& from = static_cast<const AriConfig&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:ari.AriConfig)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_port() != 0) {
    _this->_internal_set_port(from._internal_port());
  }
  if (from._internal_acceptcount() != 0) {
    _this->_internal_set_acceptcount(from._internal_acceptcount());
  }
  if (from._internal_workercount() != 0) {
    _this->_internal_set_workercount(from._internal_workercount());
  }
  if (from._internal_ipversion() != 0) {
    _this->_internal_set_ipversion(from._internal_ipversion());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void AriConfig::CopyFrom(const AriConfig& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ari.AriConfig)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool AriConfig::IsInitialized() const {
  return true;
}

void AriConfig::InternalSwap(AriConfig* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(AriConfig, _impl_.ipversion_)
      + sizeof(AriConfig::_impl_.ipversion_)
      - PROTOBUF_FIELD_OFFSET(AriConfig, _impl_.port_)>(
          reinterpret_cast<char*>(&_impl_.port_),
          reinterpret_cast<char*>(&other->_impl_.port_));
}

::PROTOBUF_NAMESPACE_ID::Metadata AriConfig::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_ari_2eproto_getter, &descriptor_table_ari_2eproto_once,
      file_level_metadata_ari_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace ari
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::ari::AriConfig*
Arena::CreateMaybeMessage< ::ari::AriConfig >(Arena* arena) {
  return Arena::CreateMessageInternal< ::ari::AriConfig >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>

// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: scenic_delete_models.proto

#include "scenic_delete_models.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)

namespace scenic_delete_models_msgs {
namespace msgs {
class ScenicDeleteModelsDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<ScenicDeleteModels>
      _instance;
} _ScenicDeleteModels_default_instance_;
}  // namespace msgs
}  // namespace scenic_delete_models_msgs
namespace protobuf_scenic_5fdelete_5fmodels_2eproto {
static void InitDefaultsScenicDeleteModels() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::scenic_delete_models_msgs::msgs::_ScenicDeleteModels_default_instance_;
    new (ptr) ::scenic_delete_models_msgs::msgs::ScenicDeleteModels();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::scenic_delete_models_msgs::msgs::ScenicDeleteModels::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_ScenicDeleteModels =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsScenicDeleteModels}, {}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_ScenicDeleteModels.base);
}

::google::protobuf::Metadata file_level_metadata[1];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::scenic_delete_models_msgs::msgs::ScenicDeleteModels, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::scenic_delete_models_msgs::msgs::ScenicDeleteModels, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::scenic_delete_models_msgs::msgs::ScenicDeleteModels, clearall_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::scenic_delete_models_msgs::msgs::ScenicDeleteModels, name_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::scenic_delete_models_msgs::msgs::ScenicDeleteModels, reset_),
  1,
  0,
  2,
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 8, sizeof(::scenic_delete_models_msgs::msgs::ScenicDeleteModels)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::scenic_delete_models_msgs::msgs::_ScenicDeleteModels_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "scenic_delete_models.proto", schemas, file_default_instances, TableStruct::offsets,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\032scenic_delete_models.proto\022\036scenic_del"
      "ete_models_msgs.msgs\"C\n\022ScenicDeleteMode"
      "ls\022\020\n\010clearAll\030\001 \002(\010\022\014\n\004name\030\002 \001(\t\022\r\n\005re"
      "set\030\003 \002(\010"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 129);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "scenic_delete_models.proto", &protobuf_RegisterTypes);
}

void AddDescriptors() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_scenic_5fdelete_5fmodels_2eproto
namespace scenic_delete_models_msgs {
namespace msgs {

// ===================================================================

void ScenicDeleteModels::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int ScenicDeleteModels::kClearAllFieldNumber;
const int ScenicDeleteModels::kNameFieldNumber;
const int ScenicDeleteModels::kResetFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

ScenicDeleteModels::ScenicDeleteModels()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_scenic_5fdelete_5fmodels_2eproto::scc_info_ScenicDeleteModels.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:scenic_delete_models_msgs.msgs.ScenicDeleteModels)
}
ScenicDeleteModels::ScenicDeleteModels(const ScenicDeleteModels& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  name_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_name()) {
    name_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.name_);
  }
  ::memcpy(&clearall_, &from.clearall_,
    static_cast<size_t>(reinterpret_cast<char*>(&reset_) -
    reinterpret_cast<char*>(&clearall_)) + sizeof(reset_));
  // @@protoc_insertion_point(copy_constructor:scenic_delete_models_msgs.msgs.ScenicDeleteModels)
}

void ScenicDeleteModels::SharedCtor() {
  name_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&clearall_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&reset_) -
      reinterpret_cast<char*>(&clearall_)) + sizeof(reset_));
}

ScenicDeleteModels::~ScenicDeleteModels() {
  // @@protoc_insertion_point(destructor:scenic_delete_models_msgs.msgs.ScenicDeleteModels)
  SharedDtor();
}

void ScenicDeleteModels::SharedDtor() {
  name_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void ScenicDeleteModels::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* ScenicDeleteModels::descriptor() {
  ::protobuf_scenic_5fdelete_5fmodels_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_scenic_5fdelete_5fmodels_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const ScenicDeleteModels& ScenicDeleteModels::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_scenic_5fdelete_5fmodels_2eproto::scc_info_ScenicDeleteModels.base);
  return *internal_default_instance();
}


void ScenicDeleteModels::Clear() {
// @@protoc_insertion_point(message_clear_start:scenic_delete_models_msgs.msgs.ScenicDeleteModels)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    name_.ClearNonDefaultToEmptyNoArena();
  }
  ::memset(&clearall_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&reset_) -
      reinterpret_cast<char*>(&clearall_)) + sizeof(reset_));
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool ScenicDeleteModels::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:scenic_delete_models_msgs.msgs.ScenicDeleteModels)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required bool clearAll = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {
          set_has_clearall();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &clearall_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional string name = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->name().data(), static_cast<int>(this->name().length()),
            ::google::protobuf::internal::WireFormat::PARSE,
            "scenic_delete_models_msgs.msgs.ScenicDeleteModels.name");
        } else {
          goto handle_unusual;
        }
        break;
      }

      // required bool reset = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(24u /* 24 & 0xFF */)) {
          set_has_reset();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &reset_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:scenic_delete_models_msgs.msgs.ScenicDeleteModels)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:scenic_delete_models_msgs.msgs.ScenicDeleteModels)
  return false;
#undef DO_
}

void ScenicDeleteModels::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:scenic_delete_models_msgs.msgs.ScenicDeleteModels)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required bool clearAll = 1;
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(1, this->clearall(), output);
  }

  // optional string name = 2;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->name().data(), static_cast<int>(this->name().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "scenic_delete_models_msgs.msgs.ScenicDeleteModels.name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->name(), output);
  }

  // required bool reset = 3;
  if (cached_has_bits & 0x00000004u) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(3, this->reset(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:scenic_delete_models_msgs.msgs.ScenicDeleteModels)
}

::google::protobuf::uint8* ScenicDeleteModels::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:scenic_delete_models_msgs.msgs.ScenicDeleteModels)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required bool clearAll = 1;
  if (cached_has_bits & 0x00000002u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(1, this->clearall(), target);
  }

  // optional string name = 2;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->name().data(), static_cast<int>(this->name().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "scenic_delete_models_msgs.msgs.ScenicDeleteModels.name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->name(), target);
  }

  // required bool reset = 3;
  if (cached_has_bits & 0x00000004u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(3, this->reset(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:scenic_delete_models_msgs.msgs.ScenicDeleteModels)
  return target;
}

size_t ScenicDeleteModels::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:scenic_delete_models_msgs.msgs.ScenicDeleteModels)
  size_t total_size = 0;

  if (has_clearall()) {
    // required bool clearAll = 1;
    total_size += 1 + 1;
  }

  if (has_reset()) {
    // required bool reset = 3;
    total_size += 1 + 1;
  }

  return total_size;
}
size_t ScenicDeleteModels::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:scenic_delete_models_msgs.msgs.ScenicDeleteModels)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  if (((_has_bits_[0] & 0x00000006) ^ 0x00000006) == 0) {  // All required fields are present.
    // required bool clearAll = 1;
    total_size += 1 + 1;

    // required bool reset = 3;
    total_size += 1 + 1;

  } else {
    total_size += RequiredFieldsByteSizeFallback();
  }
  // optional string name = 2;
  if (has_name()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->name());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void ScenicDeleteModels::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:scenic_delete_models_msgs.msgs.ScenicDeleteModels)
  GOOGLE_DCHECK_NE(&from, this);
  const ScenicDeleteModels* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const ScenicDeleteModels>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:scenic_delete_models_msgs.msgs.ScenicDeleteModels)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:scenic_delete_models_msgs.msgs.ScenicDeleteModels)
    MergeFrom(*source);
  }
}

void ScenicDeleteModels::MergeFrom(const ScenicDeleteModels& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:scenic_delete_models_msgs.msgs.ScenicDeleteModels)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 7u) {
    if (cached_has_bits & 0x00000001u) {
      set_has_name();
      name_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.name_);
    }
    if (cached_has_bits & 0x00000002u) {
      clearall_ = from.clearall_;
    }
    if (cached_has_bits & 0x00000004u) {
      reset_ = from.reset_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void ScenicDeleteModels::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:scenic_delete_models_msgs.msgs.ScenicDeleteModels)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ScenicDeleteModels::CopyFrom(const ScenicDeleteModels& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:scenic_delete_models_msgs.msgs.ScenicDeleteModels)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ScenicDeleteModels::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000006) != 0x00000006) return false;
  return true;
}

void ScenicDeleteModels::Swap(ScenicDeleteModels* other) {
  if (other == this) return;
  InternalSwap(other);
}
void ScenicDeleteModels::InternalSwap(ScenicDeleteModels* other) {
  using std::swap;
  name_.Swap(&other->name_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(clearall_, other->clearall_);
  swap(reset_, other->reset_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata ScenicDeleteModels::GetMetadata() const {
  protobuf_scenic_5fdelete_5fmodels_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_scenic_5fdelete_5fmodels_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace msgs
}  // namespace scenic_delete_models_msgs
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::scenic_delete_models_msgs::msgs::ScenicDeleteModels* Arena::CreateMaybeMessage< ::scenic_delete_models_msgs::msgs::ScenicDeleteModels >(Arena* arena) {
  return Arena::CreateInternal< ::scenic_delete_models_msgs::msgs::ScenicDeleteModels >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
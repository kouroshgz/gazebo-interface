// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: scenic_obj_info.proto

#include "scenic_obj_info.pb.h"

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

namespace protobuf_quaternion_2eproto {
extern PROTOBUF_INTERNAL_EXPORT_protobuf_quaternion_2eproto ::google::protobuf::internal::SCCInfo<0> scc_info_Quaternion;
}  // namespace protobuf_quaternion_2eproto
namespace protobuf_vector3d_2eproto {
extern PROTOBUF_INTERNAL_EXPORT_protobuf_vector3d_2eproto ::google::protobuf::internal::SCCInfo<0> scc_info_Vector3d;
}  // namespace protobuf_vector3d_2eproto
namespace scenic_obj_info_msgs {
namespace msgs {
class ScenicObjectInfoDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<ScenicObjectInfo>
      _instance;
} _ScenicObjectInfo_default_instance_;
}  // namespace msgs
}  // namespace scenic_obj_info_msgs
namespace protobuf_scenic_5fobj_5finfo_2eproto {
static void InitDefaultsScenicObjectInfo() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::scenic_obj_info_msgs::msgs::_ScenicObjectInfo_default_instance_;
    new (ptr) ::scenic_obj_info_msgs::msgs::ScenicObjectInfo();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::scenic_obj_info_msgs::msgs::ScenicObjectInfo::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<2> scc_info_ScenicObjectInfo =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 2, InitDefaultsScenicObjectInfo}, {
      &protobuf_vector3d_2eproto::scc_info_Vector3d.base,
      &protobuf_quaternion_2eproto::scc_info_Quaternion.base,}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_ScenicObjectInfo.base);
}

::google::protobuf::Metadata file_level_metadata[1];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::scenic_obj_info_msgs::msgs::ScenicObjectInfo, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::scenic_obj_info_msgs::msgs::ScenicObjectInfo, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::scenic_obj_info_msgs::msgs::ScenicObjectInfo, position_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::scenic_obj_info_msgs::msgs::ScenicObjectInfo, orientation_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::scenic_obj_info_msgs::msgs::ScenicObjectInfo, angvelocity_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::scenic_obj_info_msgs::msgs::ScenicObjectInfo, linvelocity_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::scenic_obj_info_msgs::msgs::ScenicObjectInfo, name_),
  1,
  2,
  3,
  4,
  0,
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 10, sizeof(::scenic_obj_info_msgs::msgs::ScenicObjectInfo)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::scenic_obj_info_msgs::msgs::_ScenicObjectInfo_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "scenic_obj_info.proto", schemas, file_default_instances, TableStruct::offsets,
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
      "\n\025scenic_obj_info.proto\022\031scenic_obj_info"
      "_msgs.msgs\032\016vector3d.proto\032\020quaternion.p"
      "roto\"\317\001\n\020ScenicObjectInfo\022\'\n\010position\030\001 "
      "\002(\0132\025.gazebo.msgs.Vector3d\022,\n\013orientatio"
      "n\030\002 \002(\0132\027.gazebo.msgs.Quaternion\022*\n\013angV"
      "elocity\030\003 \002(\0132\025.gazebo.msgs.Vector3d\022*\n\013"
      "linVelocity\030\004 \002(\0132\025.gazebo.msgs.Vector3d"
      "\022\014\n\004name\030\005 \002(\t"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 294);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "scenic_obj_info.proto", &protobuf_RegisterTypes);
  ::protobuf_vector3d_2eproto::AddDescriptors();
  ::protobuf_quaternion_2eproto::AddDescriptors();
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
}  // namespace protobuf_scenic_5fobj_5finfo_2eproto
namespace scenic_obj_info_msgs {
namespace msgs {

// ===================================================================

void ScenicObjectInfo::InitAsDefaultInstance() {
  ::scenic_obj_info_msgs::msgs::_ScenicObjectInfo_default_instance_._instance.get_mutable()->position_ = const_cast< ::gazebo::msgs::Vector3d*>(
      ::gazebo::msgs::Vector3d::internal_default_instance());
  ::scenic_obj_info_msgs::msgs::_ScenicObjectInfo_default_instance_._instance.get_mutable()->orientation_ = const_cast< ::gazebo::msgs::Quaternion*>(
      ::gazebo::msgs::Quaternion::internal_default_instance());
  ::scenic_obj_info_msgs::msgs::_ScenicObjectInfo_default_instance_._instance.get_mutable()->angvelocity_ = const_cast< ::gazebo::msgs::Vector3d*>(
      ::gazebo::msgs::Vector3d::internal_default_instance());
  ::scenic_obj_info_msgs::msgs::_ScenicObjectInfo_default_instance_._instance.get_mutable()->linvelocity_ = const_cast< ::gazebo::msgs::Vector3d*>(
      ::gazebo::msgs::Vector3d::internal_default_instance());
}
void ScenicObjectInfo::clear_position() {
  if (position_ != NULL) position_->Clear();
  clear_has_position();
}
void ScenicObjectInfo::clear_orientation() {
  if (orientation_ != NULL) orientation_->Clear();
  clear_has_orientation();
}
void ScenicObjectInfo::clear_angvelocity() {
  if (angvelocity_ != NULL) angvelocity_->Clear();
  clear_has_angvelocity();
}
void ScenicObjectInfo::clear_linvelocity() {
  if (linvelocity_ != NULL) linvelocity_->Clear();
  clear_has_linvelocity();
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int ScenicObjectInfo::kPositionFieldNumber;
const int ScenicObjectInfo::kOrientationFieldNumber;
const int ScenicObjectInfo::kAngVelocityFieldNumber;
const int ScenicObjectInfo::kLinVelocityFieldNumber;
const int ScenicObjectInfo::kNameFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

ScenicObjectInfo::ScenicObjectInfo()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_scenic_5fobj_5finfo_2eproto::scc_info_ScenicObjectInfo.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:scenic_obj_info_msgs.msgs.ScenicObjectInfo)
}
ScenicObjectInfo::ScenicObjectInfo(const ScenicObjectInfo& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  name_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_name()) {
    name_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.name_);
  }
  if (from.has_position()) {
    position_ = new ::gazebo::msgs::Vector3d(*from.position_);
  } else {
    position_ = NULL;
  }
  if (from.has_orientation()) {
    orientation_ = new ::gazebo::msgs::Quaternion(*from.orientation_);
  } else {
    orientation_ = NULL;
  }
  if (from.has_angvelocity()) {
    angvelocity_ = new ::gazebo::msgs::Vector3d(*from.angvelocity_);
  } else {
    angvelocity_ = NULL;
  }
  if (from.has_linvelocity()) {
    linvelocity_ = new ::gazebo::msgs::Vector3d(*from.linvelocity_);
  } else {
    linvelocity_ = NULL;
  }
  // @@protoc_insertion_point(copy_constructor:scenic_obj_info_msgs.msgs.ScenicObjectInfo)
}

void ScenicObjectInfo::SharedCtor() {
  name_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&position_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&linvelocity_) -
      reinterpret_cast<char*>(&position_)) + sizeof(linvelocity_));
}

ScenicObjectInfo::~ScenicObjectInfo() {
  // @@protoc_insertion_point(destructor:scenic_obj_info_msgs.msgs.ScenicObjectInfo)
  SharedDtor();
}

void ScenicObjectInfo::SharedDtor() {
  name_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (this != internal_default_instance()) delete position_;
  if (this != internal_default_instance()) delete orientation_;
  if (this != internal_default_instance()) delete angvelocity_;
  if (this != internal_default_instance()) delete linvelocity_;
}

void ScenicObjectInfo::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* ScenicObjectInfo::descriptor() {
  ::protobuf_scenic_5fobj_5finfo_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_scenic_5fobj_5finfo_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const ScenicObjectInfo& ScenicObjectInfo::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_scenic_5fobj_5finfo_2eproto::scc_info_ScenicObjectInfo.base);
  return *internal_default_instance();
}


void ScenicObjectInfo::Clear() {
// @@protoc_insertion_point(message_clear_start:scenic_obj_info_msgs.msgs.ScenicObjectInfo)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 31u) {
    if (cached_has_bits & 0x00000001u) {
      name_.ClearNonDefaultToEmptyNoArena();
    }
    if (cached_has_bits & 0x00000002u) {
      GOOGLE_DCHECK(position_ != NULL);
      position_->Clear();
    }
    if (cached_has_bits & 0x00000004u) {
      GOOGLE_DCHECK(orientation_ != NULL);
      orientation_->Clear();
    }
    if (cached_has_bits & 0x00000008u) {
      GOOGLE_DCHECK(angvelocity_ != NULL);
      angvelocity_->Clear();
    }
    if (cached_has_bits & 0x00000010u) {
      GOOGLE_DCHECK(linvelocity_ != NULL);
      linvelocity_->Clear();
    }
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool ScenicObjectInfo::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:scenic_obj_info_msgs.msgs.ScenicObjectInfo)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .gazebo.msgs.Vector3d position = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
               input, mutable_position()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // required .gazebo.msgs.Quaternion orientation = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
               input, mutable_orientation()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // required .gazebo.msgs.Vector3d angVelocity = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(26u /* 26 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
               input, mutable_angvelocity()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // required .gazebo.msgs.Vector3d linVelocity = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(34u /* 34 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
               input, mutable_linvelocity()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // required string name = 5;
      case 5: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(42u /* 42 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->name().data(), static_cast<int>(this->name().length()),
            ::google::protobuf::internal::WireFormat::PARSE,
            "scenic_obj_info_msgs.msgs.ScenicObjectInfo.name");
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
  // @@protoc_insertion_point(parse_success:scenic_obj_info_msgs.msgs.ScenicObjectInfo)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:scenic_obj_info_msgs.msgs.ScenicObjectInfo)
  return false;
#undef DO_
}

void ScenicObjectInfo::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:scenic_obj_info_msgs.msgs.ScenicObjectInfo)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required .gazebo.msgs.Vector3d position = 1;
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->_internal_position(), output);
  }

  // required .gazebo.msgs.Quaternion orientation = 2;
  if (cached_has_bits & 0x00000004u) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->_internal_orientation(), output);
  }

  // required .gazebo.msgs.Vector3d angVelocity = 3;
  if (cached_has_bits & 0x00000008u) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->_internal_angvelocity(), output);
  }

  // required .gazebo.msgs.Vector3d linVelocity = 4;
  if (cached_has_bits & 0x00000010u) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      4, this->_internal_linvelocity(), output);
  }

  // required string name = 5;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->name().data(), static_cast<int>(this->name().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "scenic_obj_info_msgs.msgs.ScenicObjectInfo.name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      5, this->name(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:scenic_obj_info_msgs.msgs.ScenicObjectInfo)
}

::google::protobuf::uint8* ScenicObjectInfo::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:scenic_obj_info_msgs.msgs.ScenicObjectInfo)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required .gazebo.msgs.Vector3d position = 1;
  if (cached_has_bits & 0x00000002u) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        1, this->_internal_position(), deterministic, target);
  }

  // required .gazebo.msgs.Quaternion orientation = 2;
  if (cached_has_bits & 0x00000004u) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        2, this->_internal_orientation(), deterministic, target);
  }

  // required .gazebo.msgs.Vector3d angVelocity = 3;
  if (cached_has_bits & 0x00000008u) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        3, this->_internal_angvelocity(), deterministic, target);
  }

  // required .gazebo.msgs.Vector3d linVelocity = 4;
  if (cached_has_bits & 0x00000010u) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        4, this->_internal_linvelocity(), deterministic, target);
  }

  // required string name = 5;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->name().data(), static_cast<int>(this->name().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "scenic_obj_info_msgs.msgs.ScenicObjectInfo.name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        5, this->name(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:scenic_obj_info_msgs.msgs.ScenicObjectInfo)
  return target;
}

size_t ScenicObjectInfo::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:scenic_obj_info_msgs.msgs.ScenicObjectInfo)
  size_t total_size = 0;

  if (has_name()) {
    // required string name = 5;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->name());
  }

  if (has_position()) {
    // required .gazebo.msgs.Vector3d position = 1;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSize(
        *position_);
  }

  if (has_orientation()) {
    // required .gazebo.msgs.Quaternion orientation = 2;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSize(
        *orientation_);
  }

  if (has_angvelocity()) {
    // required .gazebo.msgs.Vector3d angVelocity = 3;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSize(
        *angvelocity_);
  }

  if (has_linvelocity()) {
    // required .gazebo.msgs.Vector3d linVelocity = 4;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSize(
        *linvelocity_);
  }

  return total_size;
}
size_t ScenicObjectInfo::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:scenic_obj_info_msgs.msgs.ScenicObjectInfo)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  if (((_has_bits_[0] & 0x0000001f) ^ 0x0000001f) == 0) {  // All required fields are present.
    // required string name = 5;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->name());

    // required .gazebo.msgs.Vector3d position = 1;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSize(
        *position_);

    // required .gazebo.msgs.Quaternion orientation = 2;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSize(
        *orientation_);

    // required .gazebo.msgs.Vector3d angVelocity = 3;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSize(
        *angvelocity_);

    // required .gazebo.msgs.Vector3d linVelocity = 4;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSize(
        *linvelocity_);

  } else {
    total_size += RequiredFieldsByteSizeFallback();
  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void ScenicObjectInfo::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:scenic_obj_info_msgs.msgs.ScenicObjectInfo)
  GOOGLE_DCHECK_NE(&from, this);
  const ScenicObjectInfo* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const ScenicObjectInfo>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:scenic_obj_info_msgs.msgs.ScenicObjectInfo)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:scenic_obj_info_msgs.msgs.ScenicObjectInfo)
    MergeFrom(*source);
  }
}

void ScenicObjectInfo::MergeFrom(const ScenicObjectInfo& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:scenic_obj_info_msgs.msgs.ScenicObjectInfo)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 31u) {
    if (cached_has_bits & 0x00000001u) {
      set_has_name();
      name_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.name_);
    }
    if (cached_has_bits & 0x00000002u) {
      mutable_position()->::gazebo::msgs::Vector3d::MergeFrom(from.position());
    }
    if (cached_has_bits & 0x00000004u) {
      mutable_orientation()->::gazebo::msgs::Quaternion::MergeFrom(from.orientation());
    }
    if (cached_has_bits & 0x00000008u) {
      mutable_angvelocity()->::gazebo::msgs::Vector3d::MergeFrom(from.angvelocity());
    }
    if (cached_has_bits & 0x00000010u) {
      mutable_linvelocity()->::gazebo::msgs::Vector3d::MergeFrom(from.linvelocity());
    }
  }
}

void ScenicObjectInfo::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:scenic_obj_info_msgs.msgs.ScenicObjectInfo)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ScenicObjectInfo::CopyFrom(const ScenicObjectInfo& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:scenic_obj_info_msgs.msgs.ScenicObjectInfo)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ScenicObjectInfo::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000001f) != 0x0000001f) return false;
  if (has_position()) {
    if (!this->position_->IsInitialized()) return false;
  }
  if (has_orientation()) {
    if (!this->orientation_->IsInitialized()) return false;
  }
  if (has_angvelocity()) {
    if (!this->angvelocity_->IsInitialized()) return false;
  }
  if (has_linvelocity()) {
    if (!this->linvelocity_->IsInitialized()) return false;
  }
  return true;
}

void ScenicObjectInfo::Swap(ScenicObjectInfo* other) {
  if (other == this) return;
  InternalSwap(other);
}
void ScenicObjectInfo::InternalSwap(ScenicObjectInfo* other) {
  using std::swap;
  name_.Swap(&other->name_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(position_, other->position_);
  swap(orientation_, other->orientation_);
  swap(angvelocity_, other->angvelocity_);
  swap(linvelocity_, other->linvelocity_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata ScenicObjectInfo::GetMetadata() const {
  protobuf_scenic_5fobj_5finfo_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_scenic_5fobj_5finfo_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace msgs
}  // namespace scenic_obj_info_msgs
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::scenic_obj_info_msgs::msgs::ScenicObjectInfo* Arena::CreateMaybeMessage< ::scenic_obj_info_msgs::msgs::ScenicObjectInfo >(Arena* arena) {
  return Arena::CreateInternal< ::scenic_obj_info_msgs::msgs::ScenicObjectInfo >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
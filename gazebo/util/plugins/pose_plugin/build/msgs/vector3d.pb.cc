// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: vector3d.proto

#include "vector3d.pb.h"

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

namespace gazebo {
namespace msgs {
class Vector3dDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<Vector3d>
      _instance;
} _Vector3d_default_instance_;
}  // namespace msgs
}  // namespace gazebo
namespace protobuf_vector3d_2eproto {
static void InitDefaultsVector3d() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::gazebo::msgs::_Vector3d_default_instance_;
    new (ptr) ::gazebo::msgs::Vector3d();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::gazebo::msgs::Vector3d::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_Vector3d =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsVector3d}, {}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_Vector3d.base);
}

::google::protobuf::Metadata file_level_metadata[1];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::gazebo::msgs::Vector3d, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::gazebo::msgs::Vector3d, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::gazebo::msgs::Vector3d, x_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::gazebo::msgs::Vector3d, y_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::gazebo::msgs::Vector3d, z_),
  0,
  1,
  2,
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 8, sizeof(::gazebo::msgs::Vector3d)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::gazebo::msgs::_Vector3d_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "vector3d.proto", schemas, file_default_instances, TableStruct::offsets,
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
      "\n\016vector3d.proto\022\013gazebo.msgs\"+\n\010Vector3"
      "d\022\t\n\001x\030\001 \002(\001\022\t\n\001y\030\002 \002(\001\022\t\n\001z\030\003 \002(\001"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 74);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "vector3d.proto", &protobuf_RegisterTypes);
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
}  // namespace protobuf_vector3d_2eproto
namespace gazebo {
namespace msgs {

// ===================================================================

void Vector3d::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Vector3d::kXFieldNumber;
const int Vector3d::kYFieldNumber;
const int Vector3d::kZFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Vector3d::Vector3d()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_vector3d_2eproto::scc_info_Vector3d.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:gazebo.msgs.Vector3d)
}
Vector3d::Vector3d(const Vector3d& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::memcpy(&x_, &from.x_,
    static_cast<size_t>(reinterpret_cast<char*>(&z_) -
    reinterpret_cast<char*>(&x_)) + sizeof(z_));
  // @@protoc_insertion_point(copy_constructor:gazebo.msgs.Vector3d)
}

void Vector3d::SharedCtor() {
  ::memset(&x_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&z_) -
      reinterpret_cast<char*>(&x_)) + sizeof(z_));
}

Vector3d::~Vector3d() {
  // @@protoc_insertion_point(destructor:gazebo.msgs.Vector3d)
  SharedDtor();
}

void Vector3d::SharedDtor() {
}

void Vector3d::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* Vector3d::descriptor() {
  ::protobuf_vector3d_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_vector3d_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const Vector3d& Vector3d::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_vector3d_2eproto::scc_info_Vector3d.base);
  return *internal_default_instance();
}


void Vector3d::Clear() {
// @@protoc_insertion_point(message_clear_start:gazebo.msgs.Vector3d)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 7u) {
    ::memset(&x_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&z_) -
        reinterpret_cast<char*>(&x_)) + sizeof(z_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool Vector3d::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:gazebo.msgs.Vector3d)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required double x = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(9u /* 9 & 0xFF */)) {
          set_has_x();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &x_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // required double y = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(17u /* 17 & 0xFF */)) {
          set_has_y();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &y_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // required double z = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(25u /* 25 & 0xFF */)) {
          set_has_z();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &z_)));
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
  // @@protoc_insertion_point(parse_success:gazebo.msgs.Vector3d)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:gazebo.msgs.Vector3d)
  return false;
#undef DO_
}

void Vector3d::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:gazebo.msgs.Vector3d)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required double x = 1;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(1, this->x(), output);
  }

  // required double y = 2;
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(2, this->y(), output);
  }

  // required double z = 3;
  if (cached_has_bits & 0x00000004u) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(3, this->z(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:gazebo.msgs.Vector3d)
}

::google::protobuf::uint8* Vector3d::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:gazebo.msgs.Vector3d)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required double x = 1;
  if (cached_has_bits & 0x00000001u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(1, this->x(), target);
  }

  // required double y = 2;
  if (cached_has_bits & 0x00000002u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(2, this->y(), target);
  }

  // required double z = 3;
  if (cached_has_bits & 0x00000004u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(3, this->z(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:gazebo.msgs.Vector3d)
  return target;
}

size_t Vector3d::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:gazebo.msgs.Vector3d)
  size_t total_size = 0;

  if (has_x()) {
    // required double x = 1;
    total_size += 1 + 8;
  }

  if (has_y()) {
    // required double y = 2;
    total_size += 1 + 8;
  }

  if (has_z()) {
    // required double z = 3;
    total_size += 1 + 8;
  }

  return total_size;
}
size_t Vector3d::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:gazebo.msgs.Vector3d)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  if (((_has_bits_[0] & 0x00000007) ^ 0x00000007) == 0) {  // All required fields are present.
    // required double x = 1;
    total_size += 1 + 8;

    // required double y = 2;
    total_size += 1 + 8;

    // required double z = 3;
    total_size += 1 + 8;

  } else {
    total_size += RequiredFieldsByteSizeFallback();
  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Vector3d::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:gazebo.msgs.Vector3d)
  GOOGLE_DCHECK_NE(&from, this);
  const Vector3d* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const Vector3d>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:gazebo.msgs.Vector3d)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:gazebo.msgs.Vector3d)
    MergeFrom(*source);
  }
}

void Vector3d::MergeFrom(const Vector3d& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:gazebo.msgs.Vector3d)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 7u) {
    if (cached_has_bits & 0x00000001u) {
      x_ = from.x_;
    }
    if (cached_has_bits & 0x00000002u) {
      y_ = from.y_;
    }
    if (cached_has_bits & 0x00000004u) {
      z_ = from.z_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void Vector3d::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:gazebo.msgs.Vector3d)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Vector3d::CopyFrom(const Vector3d& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:gazebo.msgs.Vector3d)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Vector3d::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000007) != 0x00000007) return false;
  return true;
}

void Vector3d::Swap(Vector3d* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Vector3d::InternalSwap(Vector3d* other) {
  using std::swap;
  swap(x_, other->x_);
  swap(y_, other->y_);
  swap(z_, other->z_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata Vector3d::GetMetadata() const {
  protobuf_vector3d_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_vector3d_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace msgs
}  // namespace gazebo
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::gazebo::msgs::Vector3d* Arena::CreateMaybeMessage< ::gazebo::msgs::Vector3d >(Arena* arena) {
  return Arena::CreateInternal< ::gazebo::msgs::Vector3d >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
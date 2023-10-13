// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: company_info.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_company_5finfo_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_company_5finfo_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>

#include "google/protobuf/port_def.inc"
#if PROTOBUF_VERSION < 4023000
#error "This file was generated by a newer version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please update"
#error "your headers."
#endif  // PROTOBUF_VERSION

#if 4023004 < PROTOBUF_MIN_PROTOC_VERSION
#error "This file was generated by an older version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please"
#error "regenerate this file with a newer version of protoc."
#endif  // PROTOBUF_MIN_PROTOC_VERSION
#include "google/protobuf/port_undef.inc"
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/unknown_field_set.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_company_5finfo_2eproto

PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_company_5finfo_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable
    descriptor_table_company_5finfo_2eproto;
class company_info;
struct company_infoDefaultTypeInternal;
extern company_infoDefaultTypeInternal _company_info_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template <>
::company_info* Arena::CreateMaybeMessage<::company_info>(Arena*);
PROTOBUF_NAMESPACE_CLOSE


// ===================================================================


// -------------------------------------------------------------------

class company_info final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:company_info) */ {
 public:
  inline company_info() : company_info(nullptr) {}
  ~company_info() override;
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR company_info(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  company_info(const company_info& from);
  company_info(company_info&& from) noexcept
    : company_info() {
    *this = ::std::move(from);
  }

  inline company_info& operator=(const company_info& from) {
    CopyFrom(from);
    return *this;
  }
  inline company_info& operator=(company_info&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const company_info& default_instance() {
    return *internal_default_instance();
  }
  static inline const company_info* internal_default_instance() {
    return reinterpret_cast<const company_info*>(
               &_company_info_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(company_info& a, company_info& b) {
    a.Swap(&b);
  }
  inline void Swap(company_info* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(company_info* other) {
    if (other == this) return;
    ABSL_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  company_info* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<company_info>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const company_info& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const company_info& from) {
    company_info::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(company_info* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "company_info";
  }
  protected:
  explicit company_info(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kLegalAddressFieldNumber = 2,
    kNameFieldNumber = 3,
    kOccupationFieldNumber = 4,
    kFoundedFieldNumber = 1,
    kForeignActivityFieldNumber = 5,
  };
  // required string legal_address = 2;
  bool has_legal_address() const;
  void clear_legal_address() ;
  const std::string& legal_address() const;




  template <typename Arg_ = const std::string&, typename... Args_>
  void set_legal_address(Arg_&& arg, Args_... args);
  std::string* mutable_legal_address();
  PROTOBUF_NODISCARD std::string* release_legal_address();
  void set_allocated_legal_address(std::string* ptr);

  private:
  const std::string& _internal_legal_address() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_legal_address(
      const std::string& value);
  std::string* _internal_mutable_legal_address();

  public:
  // required string name = 3;
  bool has_name() const;
  void clear_name() ;
  const std::string& name() const;




  template <typename Arg_ = const std::string&, typename... Args_>
  void set_name(Arg_&& arg, Args_... args);
  std::string* mutable_name();
  PROTOBUF_NODISCARD std::string* release_name();
  void set_allocated_name(std::string* ptr);

  private:
  const std::string& _internal_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(
      const std::string& value);
  std::string* _internal_mutable_name();

  public:
  // optional string occupation = 4;
  bool has_occupation() const;
  void clear_occupation() ;
  const std::string& occupation() const;




  template <typename Arg_ = const std::string&, typename... Args_>
  void set_occupation(Arg_&& arg, Args_... args);
  std::string* mutable_occupation();
  PROTOBUF_NODISCARD std::string* release_occupation();
  void set_allocated_occupation(std::string* ptr);

  private:
  const std::string& _internal_occupation() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_occupation(
      const std::string& value);
  std::string* _internal_mutable_occupation();

  public:
  // required int32 founded = 1;
  bool has_founded() const;
  void clear_founded() ;
  ::int32_t founded() const;
  void set_founded(::int32_t value);

  private:
  ::int32_t _internal_founded() const;
  void _internal_set_founded(::int32_t value);

  public:
  // optional bool foreign_activity = 5;
  bool has_foreign_activity() const;
  void clear_foreign_activity() ;
  bool foreign_activity() const;
  void set_foreign_activity(bool value);

  private:
  bool _internal_foreign_activity() const;
  void _internal_set_foreign_activity(bool value);

  public:
  // @@protoc_insertion_point(class_scope:company_info)
 private:
  class _Internal;

  // helper for ByteSizeLong()
  ::size_t RequiredFieldsByteSizeFallback() const;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr legal_address_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr occupation_;
    ::int32_t founded_;
    bool foreign_activity_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_company_5finfo_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// company_info

// required int32 founded = 1;
inline bool company_info::has_founded() const {
  bool value = (_impl_._has_bits_[0] & 0x00000008u) != 0;
  return value;
}
inline void company_info::clear_founded() {
  _impl_.founded_ = 0;
  _impl_._has_bits_[0] &= ~0x00000008u;
}
inline ::int32_t company_info::founded() const {
  // @@protoc_insertion_point(field_get:company_info.founded)
  return _internal_founded();
}
inline void company_info::set_founded(::int32_t value) {
  _internal_set_founded(value);
  // @@protoc_insertion_point(field_set:company_info.founded)
}
inline ::int32_t company_info::_internal_founded() const {
  return _impl_.founded_;
}
inline void company_info::_internal_set_founded(::int32_t value) {
  _impl_._has_bits_[0] |= 0x00000008u;
  _impl_.founded_ = value;
}

// required string legal_address = 2;
inline bool company_info::has_legal_address() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline void company_info::clear_legal_address() {
  _impl_.legal_address_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline const std::string& company_info::legal_address() const {
  // @@protoc_insertion_point(field_get:company_info.legal_address)
  return _internal_legal_address();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void company_info::set_legal_address(Arg_&& arg,
                                                     Args_... args) {
  _impl_._has_bits_[0] |= 0x00000001u;
  _impl_.legal_address_.Set(static_cast<Arg_&&>(arg), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:company_info.legal_address)
}
inline std::string* company_info::mutable_legal_address() {
  std::string* _s = _internal_mutable_legal_address();
  // @@protoc_insertion_point(field_mutable:company_info.legal_address)
  return _s;
}
inline const std::string& company_info::_internal_legal_address() const {
  return _impl_.legal_address_.Get();
}
inline void company_info::_internal_set_legal_address(const std::string& value) {
  _impl_._has_bits_[0] |= 0x00000001u;


  _impl_.legal_address_.Set(value, GetArenaForAllocation());
}
inline std::string* company_info::_internal_mutable_legal_address() {
  _impl_._has_bits_[0] |= 0x00000001u;
  return _impl_.legal_address_.Mutable( GetArenaForAllocation());
}
inline std::string* company_info::release_legal_address() {
  // @@protoc_insertion_point(field_release:company_info.legal_address)
  if ((_impl_._has_bits_[0] & 0x00000001u) == 0) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000001u;
  auto* released = _impl_.legal_address_.Release();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.legal_address_.Set("", GetArenaForAllocation());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return released;
}
inline void company_info::set_allocated_legal_address(std::string* value) {
  if (value != nullptr) {
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }
  _impl_.legal_address_.SetAllocated(value, GetArenaForAllocation());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.legal_address_.IsDefault()) {
          _impl_.legal_address_.Set("", GetArenaForAllocation());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:company_info.legal_address)
}

// required string name = 3;
inline bool company_info::has_name() const {
  bool value = (_impl_._has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline void company_info::clear_name() {
  _impl_.name_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000002u;
}
inline const std::string& company_info::name() const {
  // @@protoc_insertion_point(field_get:company_info.name)
  return _internal_name();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void company_info::set_name(Arg_&& arg,
                                                     Args_... args) {
  _impl_._has_bits_[0] |= 0x00000002u;
  _impl_.name_.Set(static_cast<Arg_&&>(arg), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:company_info.name)
}
inline std::string* company_info::mutable_name() {
  std::string* _s = _internal_mutable_name();
  // @@protoc_insertion_point(field_mutable:company_info.name)
  return _s;
}
inline const std::string& company_info::_internal_name() const {
  return _impl_.name_.Get();
}
inline void company_info::_internal_set_name(const std::string& value) {
  _impl_._has_bits_[0] |= 0x00000002u;


  _impl_.name_.Set(value, GetArenaForAllocation());
}
inline std::string* company_info::_internal_mutable_name() {
  _impl_._has_bits_[0] |= 0x00000002u;
  return _impl_.name_.Mutable( GetArenaForAllocation());
}
inline std::string* company_info::release_name() {
  // @@protoc_insertion_point(field_release:company_info.name)
  if ((_impl_._has_bits_[0] & 0x00000002u) == 0) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000002u;
  auto* released = _impl_.name_.Release();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.name_.Set("", GetArenaForAllocation());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return released;
}
inline void company_info::set_allocated_name(std::string* value) {
  if (value != nullptr) {
    _impl_._has_bits_[0] |= 0x00000002u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000002u;
  }
  _impl_.name_.SetAllocated(value, GetArenaForAllocation());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.name_.IsDefault()) {
          _impl_.name_.Set("", GetArenaForAllocation());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:company_info.name)
}

// optional string occupation = 4;
inline bool company_info::has_occupation() const {
  bool value = (_impl_._has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline void company_info::clear_occupation() {
  _impl_.occupation_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000004u;
}
inline const std::string& company_info::occupation() const {
  // @@protoc_insertion_point(field_get:company_info.occupation)
  return _internal_occupation();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void company_info::set_occupation(Arg_&& arg,
                                                     Args_... args) {
  _impl_._has_bits_[0] |= 0x00000004u;
  _impl_.occupation_.Set(static_cast<Arg_&&>(arg), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:company_info.occupation)
}
inline std::string* company_info::mutable_occupation() {
  std::string* _s = _internal_mutable_occupation();
  // @@protoc_insertion_point(field_mutable:company_info.occupation)
  return _s;
}
inline const std::string& company_info::_internal_occupation() const {
  return _impl_.occupation_.Get();
}
inline void company_info::_internal_set_occupation(const std::string& value) {
  _impl_._has_bits_[0] |= 0x00000004u;


  _impl_.occupation_.Set(value, GetArenaForAllocation());
}
inline std::string* company_info::_internal_mutable_occupation() {
  _impl_._has_bits_[0] |= 0x00000004u;
  return _impl_.occupation_.Mutable( GetArenaForAllocation());
}
inline std::string* company_info::release_occupation() {
  // @@protoc_insertion_point(field_release:company_info.occupation)
  if ((_impl_._has_bits_[0] & 0x00000004u) == 0) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000004u;
  auto* released = _impl_.occupation_.Release();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.occupation_.Set("", GetArenaForAllocation());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return released;
}
inline void company_info::set_allocated_occupation(std::string* value) {
  if (value != nullptr) {
    _impl_._has_bits_[0] |= 0x00000004u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000004u;
  }
  _impl_.occupation_.SetAllocated(value, GetArenaForAllocation());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.occupation_.IsDefault()) {
          _impl_.occupation_.Set("", GetArenaForAllocation());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:company_info.occupation)
}

// optional bool foreign_activity = 5;
inline bool company_info::has_foreign_activity() const {
  bool value = (_impl_._has_bits_[0] & 0x00000010u) != 0;
  return value;
}
inline void company_info::clear_foreign_activity() {
  _impl_.foreign_activity_ = false;
  _impl_._has_bits_[0] &= ~0x00000010u;
}
inline bool company_info::foreign_activity() const {
  // @@protoc_insertion_point(field_get:company_info.foreign_activity)
  return _internal_foreign_activity();
}
inline void company_info::set_foreign_activity(bool value) {
  _internal_set_foreign_activity(value);
  // @@protoc_insertion_point(field_set:company_info.foreign_activity)
}
inline bool company_info::_internal_foreign_activity() const {
  return _impl_.foreign_activity_;
}
inline void company_info::_internal_set_foreign_activity(bool value) {
  _impl_._has_bits_[0] |= 0x00000010u;
  _impl_.foreign_activity_ = value;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_company_5finfo_2eproto_2epb_2eh

// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: monitor_info.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_monitor_5finfo_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_monitor_5finfo_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3014000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3014000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include <google/protobuf/empty.pb.h>
#include "net_info.pb.h"
#include "mem_info.pb.h"
#include "cpu_stat.pb.h"
#include "cpu_softirqs.pb.h"
#include "cpu_load.pb.h"
#include "parsing_log.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_monitor_5finfo_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_monitor_5finfo_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_monitor_5finfo_2eproto;
namespace monitor {
namespace proto {
class MonitorInfo;
class MonitorInfoDefaultTypeInternal;
extern MonitorInfoDefaultTypeInternal _MonitorInfo_default_instance_;
}  // namespace proto
}  // namespace monitor
PROTOBUF_NAMESPACE_OPEN
template<> ::monitor::proto::MonitorInfo* Arena::CreateMaybeMessage<::monitor::proto::MonitorInfo>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace monitor {
namespace proto {

// ===================================================================

class MonitorInfo PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:monitor.proto.MonitorInfo) */ {
 public:
  inline MonitorInfo() : MonitorInfo(nullptr) {}
  virtual ~MonitorInfo();

  MonitorInfo(const MonitorInfo& from);
  MonitorInfo(MonitorInfo&& from) noexcept
    : MonitorInfo() {
    *this = ::std::move(from);
  }

  inline MonitorInfo& operator=(const MonitorInfo& from) {
    CopyFrom(from);
    return *this;
  }
  inline MonitorInfo& operator=(MonitorInfo&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const MonitorInfo& default_instance();

  static inline const MonitorInfo* internal_default_instance() {
    return reinterpret_cast<const MonitorInfo*>(
               &_MonitorInfo_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(MonitorInfo& a, MonitorInfo& b) {
    a.Swap(&b);
  }
  inline void Swap(MonitorInfo* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(MonitorInfo* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline MonitorInfo* New() const final {
    return CreateMaybeMessage<MonitorInfo>(nullptr);
  }

  MonitorInfo* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<MonitorInfo>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const MonitorInfo& from);
  void MergeFrom(const MonitorInfo& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(MonitorInfo* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "monitor.proto.MonitorInfo";
  }
  protected:
  explicit MonitorInfo(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_monitor_5finfo_2eproto);
    return ::descriptor_table_monitor_5finfo_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kSoftIrqFieldNumber = 2,
    kCpuStatFieldNumber = 4,
    kNetInfoFieldNumber = 6,
    kNameFieldNumber = 1,
    kCpuLoadFieldNumber = 3,
    kMemInfoFieldNumber = 5,
    kParsingLogFieldNumber = 7,
  };
  // repeated .monitor.proto.SoftIrqs soft_irq = 2;
  int soft_irq_size() const;
  private:
  int _internal_soft_irq_size() const;
  public:
  void clear_soft_irq();
  ::monitor::proto::SoftIrqs* mutable_soft_irq(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::monitor::proto::SoftIrqs >*
      mutable_soft_irq();
  private:
  const ::monitor::proto::SoftIrqs& _internal_soft_irq(int index) const;
  ::monitor::proto::SoftIrqs* _internal_add_soft_irq();
  public:
  const ::monitor::proto::SoftIrqs& soft_irq(int index) const;
  ::monitor::proto::SoftIrqs* add_soft_irq();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::monitor::proto::SoftIrqs >&
      soft_irq() const;

  // repeated .monitor.proto.CpuStat cpu_stat = 4;
  int cpu_stat_size() const;
  private:
  int _internal_cpu_stat_size() const;
  public:
  void clear_cpu_stat();
  ::monitor::proto::CpuStat* mutable_cpu_stat(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::monitor::proto::CpuStat >*
      mutable_cpu_stat();
  private:
  const ::monitor::proto::CpuStat& _internal_cpu_stat(int index) const;
  ::monitor::proto::CpuStat* _internal_add_cpu_stat();
  public:
  const ::monitor::proto::CpuStat& cpu_stat(int index) const;
  ::monitor::proto::CpuStat* add_cpu_stat();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::monitor::proto::CpuStat >&
      cpu_stat() const;

  // repeated .monitor.proto.NetInfo net_info = 6;
  int net_info_size() const;
  private:
  int _internal_net_info_size() const;
  public:
  void clear_net_info();
  ::monitor::proto::NetInfo* mutable_net_info(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::monitor::proto::NetInfo >*
      mutable_net_info();
  private:
  const ::monitor::proto::NetInfo& _internal_net_info(int index) const;
  ::monitor::proto::NetInfo* _internal_add_net_info();
  public:
  const ::monitor::proto::NetInfo& net_info(int index) const;
  ::monitor::proto::NetInfo* add_net_info();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::monitor::proto::NetInfo >&
      net_info() const;

  // string name = 1;
  void clear_name();
  const std::string& name() const;
  void set_name(const std::string& value);
  void set_name(std::string&& value);
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  std::string* mutable_name();
  std::string* release_name();
  void set_allocated_name(std::string* name);
  private:
  const std::string& _internal_name() const;
  void _internal_set_name(const std::string& value);
  std::string* _internal_mutable_name();
  public:

  // .monitor.proto.CpuLoad cpu_load = 3;
  bool has_cpu_load() const;
  private:
  bool _internal_has_cpu_load() const;
  public:
  void clear_cpu_load();
  const ::monitor::proto::CpuLoad& cpu_load() const;
  ::monitor::proto::CpuLoad* release_cpu_load();
  ::monitor::proto::CpuLoad* mutable_cpu_load();
  void set_allocated_cpu_load(::monitor::proto::CpuLoad* cpu_load);
  private:
  const ::monitor::proto::CpuLoad& _internal_cpu_load() const;
  ::monitor::proto::CpuLoad* _internal_mutable_cpu_load();
  public:
  void unsafe_arena_set_allocated_cpu_load(
      ::monitor::proto::CpuLoad* cpu_load);
  ::monitor::proto::CpuLoad* unsafe_arena_release_cpu_load();

  // .monitor.proto.MemInfo mem_info = 5;
  bool has_mem_info() const;
  private:
  bool _internal_has_mem_info() const;
  public:
  void clear_mem_info();
  const ::monitor::proto::MemInfo& mem_info() const;
  ::monitor::proto::MemInfo* release_mem_info();
  ::monitor::proto::MemInfo* mutable_mem_info();
  void set_allocated_mem_info(::monitor::proto::MemInfo* mem_info);
  private:
  const ::monitor::proto::MemInfo& _internal_mem_info() const;
  ::monitor::proto::MemInfo* _internal_mutable_mem_info();
  public:
  void unsafe_arena_set_allocated_mem_info(
      ::monitor::proto::MemInfo* mem_info);
  ::monitor::proto::MemInfo* unsafe_arena_release_mem_info();

  // .monitor.proto.ParsingLog parsing_log = 7;
  bool has_parsing_log() const;
  private:
  bool _internal_has_parsing_log() const;
  public:
  void clear_parsing_log();
  const ::monitor::proto::ParsingLog& parsing_log() const;
  ::monitor::proto::ParsingLog* release_parsing_log();
  ::monitor::proto::ParsingLog* mutable_parsing_log();
  void set_allocated_parsing_log(::monitor::proto::ParsingLog* parsing_log);
  private:
  const ::monitor::proto::ParsingLog& _internal_parsing_log() const;
  ::monitor::proto::ParsingLog* _internal_mutable_parsing_log();
  public:
  void unsafe_arena_set_allocated_parsing_log(
      ::monitor::proto::ParsingLog* parsing_log);
  ::monitor::proto::ParsingLog* unsafe_arena_release_parsing_log();

  // @@protoc_insertion_point(class_scope:monitor.proto.MonitorInfo)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::monitor::proto::SoftIrqs > soft_irq_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::monitor::proto::CpuStat > cpu_stat_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::monitor::proto::NetInfo > net_info_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
  ::monitor::proto::CpuLoad* cpu_load_;
  ::monitor::proto::MemInfo* mem_info_;
  ::monitor::proto::ParsingLog* parsing_log_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_monitor_5finfo_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// MonitorInfo

// string name = 1;
inline void MonitorInfo::clear_name() {
  name_.ClearToEmpty();
}
inline const std::string& MonitorInfo::name() const {
  // @@protoc_insertion_point(field_get:monitor.proto.MonitorInfo.name)
  return _internal_name();
}
inline void MonitorInfo::set_name(const std::string& value) {
  _internal_set_name(value);
  // @@protoc_insertion_point(field_set:monitor.proto.MonitorInfo.name)
}
inline std::string* MonitorInfo::mutable_name() {
  // @@protoc_insertion_point(field_mutable:monitor.proto.MonitorInfo.name)
  return _internal_mutable_name();
}
inline const std::string& MonitorInfo::_internal_name() const {
  return name_.Get();
}
inline void MonitorInfo::_internal_set_name(const std::string& value) {
  
  name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArena());
}
inline void MonitorInfo::set_name(std::string&& value) {
  
  name_.Set(
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:monitor.proto.MonitorInfo.name)
}
inline void MonitorInfo::set_name(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(value), GetArena());
  // @@protoc_insertion_point(field_set_char:monitor.proto.MonitorInfo.name)
}
inline void MonitorInfo::set_name(const char* value,
    size_t size) {
  
  name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:monitor.proto.MonitorInfo.name)
}
inline std::string* MonitorInfo::_internal_mutable_name() {
  
  return name_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
}
inline std::string* MonitorInfo::release_name() {
  // @@protoc_insertion_point(field_release:monitor.proto.MonitorInfo.name)
  return name_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void MonitorInfo::set_allocated_name(std::string* name) {
  if (name != nullptr) {
    
  } else {
    
  }
  name_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), name,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:monitor.proto.MonitorInfo.name)
}

// repeated .monitor.proto.SoftIrqs soft_irq = 2;
inline int MonitorInfo::_internal_soft_irq_size() const {
  return soft_irq_.size();
}
inline int MonitorInfo::soft_irq_size() const {
  return _internal_soft_irq_size();
}
inline ::monitor::proto::SoftIrqs* MonitorInfo::mutable_soft_irq(int index) {
  // @@protoc_insertion_point(field_mutable:monitor.proto.MonitorInfo.soft_irq)
  return soft_irq_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::monitor::proto::SoftIrqs >*
MonitorInfo::mutable_soft_irq() {
  // @@protoc_insertion_point(field_mutable_list:monitor.proto.MonitorInfo.soft_irq)
  return &soft_irq_;
}
inline const ::monitor::proto::SoftIrqs& MonitorInfo::_internal_soft_irq(int index) const {
  return soft_irq_.Get(index);
}
inline const ::monitor::proto::SoftIrqs& MonitorInfo::soft_irq(int index) const {
  // @@protoc_insertion_point(field_get:monitor.proto.MonitorInfo.soft_irq)
  return _internal_soft_irq(index);
}
inline ::monitor::proto::SoftIrqs* MonitorInfo::_internal_add_soft_irq() {
  return soft_irq_.Add();
}
inline ::monitor::proto::SoftIrqs* MonitorInfo::add_soft_irq() {
  // @@protoc_insertion_point(field_add:monitor.proto.MonitorInfo.soft_irq)
  return _internal_add_soft_irq();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::monitor::proto::SoftIrqs >&
MonitorInfo::soft_irq() const {
  // @@protoc_insertion_point(field_list:monitor.proto.MonitorInfo.soft_irq)
  return soft_irq_;
}

// .monitor.proto.CpuLoad cpu_load = 3;
inline bool MonitorInfo::_internal_has_cpu_load() const {
  return this != internal_default_instance() && cpu_load_ != nullptr;
}
inline bool MonitorInfo::has_cpu_load() const {
  return _internal_has_cpu_load();
}
inline const ::monitor::proto::CpuLoad& MonitorInfo::_internal_cpu_load() const {
  const ::monitor::proto::CpuLoad* p = cpu_load_;
  return p != nullptr ? *p : reinterpret_cast<const ::monitor::proto::CpuLoad&>(
      ::monitor::proto::_CpuLoad_default_instance_);
}
inline const ::monitor::proto::CpuLoad& MonitorInfo::cpu_load() const {
  // @@protoc_insertion_point(field_get:monitor.proto.MonitorInfo.cpu_load)
  return _internal_cpu_load();
}
inline void MonitorInfo::unsafe_arena_set_allocated_cpu_load(
    ::monitor::proto::CpuLoad* cpu_load) {
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(cpu_load_);
  }
  cpu_load_ = cpu_load;
  if (cpu_load) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:monitor.proto.MonitorInfo.cpu_load)
}
inline ::monitor::proto::CpuLoad* MonitorInfo::release_cpu_load() {
  
  ::monitor::proto::CpuLoad* temp = cpu_load_;
  cpu_load_ = nullptr;
  if (GetArena() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
  return temp;
}
inline ::monitor::proto::CpuLoad* MonitorInfo::unsafe_arena_release_cpu_load() {
  // @@protoc_insertion_point(field_release:monitor.proto.MonitorInfo.cpu_load)
  
  ::monitor::proto::CpuLoad* temp = cpu_load_;
  cpu_load_ = nullptr;
  return temp;
}
inline ::monitor::proto::CpuLoad* MonitorInfo::_internal_mutable_cpu_load() {
  
  if (cpu_load_ == nullptr) {
    auto* p = CreateMaybeMessage<::monitor::proto::CpuLoad>(GetArena());
    cpu_load_ = p;
  }
  return cpu_load_;
}
inline ::monitor::proto::CpuLoad* MonitorInfo::mutable_cpu_load() {
  // @@protoc_insertion_point(field_mutable:monitor.proto.MonitorInfo.cpu_load)
  return _internal_mutable_cpu_load();
}
inline void MonitorInfo::set_allocated_cpu_load(::monitor::proto::CpuLoad* cpu_load) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArena();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(cpu_load_);
  }
  if (cpu_load) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
      reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(cpu_load)->GetArena();
    if (message_arena != submessage_arena) {
      cpu_load = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, cpu_load, submessage_arena);
    }
    
  } else {
    
  }
  cpu_load_ = cpu_load;
  // @@protoc_insertion_point(field_set_allocated:monitor.proto.MonitorInfo.cpu_load)
}

// repeated .monitor.proto.CpuStat cpu_stat = 4;
inline int MonitorInfo::_internal_cpu_stat_size() const {
  return cpu_stat_.size();
}
inline int MonitorInfo::cpu_stat_size() const {
  return _internal_cpu_stat_size();
}
inline ::monitor::proto::CpuStat* MonitorInfo::mutable_cpu_stat(int index) {
  // @@protoc_insertion_point(field_mutable:monitor.proto.MonitorInfo.cpu_stat)
  return cpu_stat_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::monitor::proto::CpuStat >*
MonitorInfo::mutable_cpu_stat() {
  // @@protoc_insertion_point(field_mutable_list:monitor.proto.MonitorInfo.cpu_stat)
  return &cpu_stat_;
}
inline const ::monitor::proto::CpuStat& MonitorInfo::_internal_cpu_stat(int index) const {
  return cpu_stat_.Get(index);
}
inline const ::monitor::proto::CpuStat& MonitorInfo::cpu_stat(int index) const {
  // @@protoc_insertion_point(field_get:monitor.proto.MonitorInfo.cpu_stat)
  return _internal_cpu_stat(index);
}
inline ::monitor::proto::CpuStat* MonitorInfo::_internal_add_cpu_stat() {
  return cpu_stat_.Add();
}
inline ::monitor::proto::CpuStat* MonitorInfo::add_cpu_stat() {
  // @@protoc_insertion_point(field_add:monitor.proto.MonitorInfo.cpu_stat)
  return _internal_add_cpu_stat();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::monitor::proto::CpuStat >&
MonitorInfo::cpu_stat() const {
  // @@protoc_insertion_point(field_list:monitor.proto.MonitorInfo.cpu_stat)
  return cpu_stat_;
}

// .monitor.proto.MemInfo mem_info = 5;
inline bool MonitorInfo::_internal_has_mem_info() const {
  return this != internal_default_instance() && mem_info_ != nullptr;
}
inline bool MonitorInfo::has_mem_info() const {
  return _internal_has_mem_info();
}
inline const ::monitor::proto::MemInfo& MonitorInfo::_internal_mem_info() const {
  const ::monitor::proto::MemInfo* p = mem_info_;
  return p != nullptr ? *p : reinterpret_cast<const ::monitor::proto::MemInfo&>(
      ::monitor::proto::_MemInfo_default_instance_);
}
inline const ::monitor::proto::MemInfo& MonitorInfo::mem_info() const {
  // @@protoc_insertion_point(field_get:monitor.proto.MonitorInfo.mem_info)
  return _internal_mem_info();
}
inline void MonitorInfo::unsafe_arena_set_allocated_mem_info(
    ::monitor::proto::MemInfo* mem_info) {
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(mem_info_);
  }
  mem_info_ = mem_info;
  if (mem_info) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:monitor.proto.MonitorInfo.mem_info)
}
inline ::monitor::proto::MemInfo* MonitorInfo::release_mem_info() {
  
  ::monitor::proto::MemInfo* temp = mem_info_;
  mem_info_ = nullptr;
  if (GetArena() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
  return temp;
}
inline ::monitor::proto::MemInfo* MonitorInfo::unsafe_arena_release_mem_info() {
  // @@protoc_insertion_point(field_release:monitor.proto.MonitorInfo.mem_info)
  
  ::monitor::proto::MemInfo* temp = mem_info_;
  mem_info_ = nullptr;
  return temp;
}
inline ::monitor::proto::MemInfo* MonitorInfo::_internal_mutable_mem_info() {
  
  if (mem_info_ == nullptr) {
    auto* p = CreateMaybeMessage<::monitor::proto::MemInfo>(GetArena());
    mem_info_ = p;
  }
  return mem_info_;
}
inline ::monitor::proto::MemInfo* MonitorInfo::mutable_mem_info() {
  // @@protoc_insertion_point(field_mutable:monitor.proto.MonitorInfo.mem_info)
  return _internal_mutable_mem_info();
}
inline void MonitorInfo::set_allocated_mem_info(::monitor::proto::MemInfo* mem_info) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArena();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(mem_info_);
  }
  if (mem_info) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
      reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(mem_info)->GetArena();
    if (message_arena != submessage_arena) {
      mem_info = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, mem_info, submessage_arena);
    }
    
  } else {
    
  }
  mem_info_ = mem_info;
  // @@protoc_insertion_point(field_set_allocated:monitor.proto.MonitorInfo.mem_info)
}

// repeated .monitor.proto.NetInfo net_info = 6;
inline int MonitorInfo::_internal_net_info_size() const {
  return net_info_.size();
}
inline int MonitorInfo::net_info_size() const {
  return _internal_net_info_size();
}
inline ::monitor::proto::NetInfo* MonitorInfo::mutable_net_info(int index) {
  // @@protoc_insertion_point(field_mutable:monitor.proto.MonitorInfo.net_info)
  return net_info_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::monitor::proto::NetInfo >*
MonitorInfo::mutable_net_info() {
  // @@protoc_insertion_point(field_mutable_list:monitor.proto.MonitorInfo.net_info)
  return &net_info_;
}
inline const ::monitor::proto::NetInfo& MonitorInfo::_internal_net_info(int index) const {
  return net_info_.Get(index);
}
inline const ::monitor::proto::NetInfo& MonitorInfo::net_info(int index) const {
  // @@protoc_insertion_point(field_get:monitor.proto.MonitorInfo.net_info)
  return _internal_net_info(index);
}
inline ::monitor::proto::NetInfo* MonitorInfo::_internal_add_net_info() {
  return net_info_.Add();
}
inline ::monitor::proto::NetInfo* MonitorInfo::add_net_info() {
  // @@protoc_insertion_point(field_add:monitor.proto.MonitorInfo.net_info)
  return _internal_add_net_info();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::monitor::proto::NetInfo >&
MonitorInfo::net_info() const {
  // @@protoc_insertion_point(field_list:monitor.proto.MonitorInfo.net_info)
  return net_info_;
}

// .monitor.proto.ParsingLog parsing_log = 7;
inline bool MonitorInfo::_internal_has_parsing_log() const {
  return this != internal_default_instance() && parsing_log_ != nullptr;
}
inline bool MonitorInfo::has_parsing_log() const {
  return _internal_has_parsing_log();
}
inline const ::monitor::proto::ParsingLog& MonitorInfo::_internal_parsing_log() const {
  const ::monitor::proto::ParsingLog* p = parsing_log_;
  return p != nullptr ? *p : reinterpret_cast<const ::monitor::proto::ParsingLog&>(
      ::monitor::proto::_ParsingLog_default_instance_);
}
inline const ::monitor::proto::ParsingLog& MonitorInfo::parsing_log() const {
  // @@protoc_insertion_point(field_get:monitor.proto.MonitorInfo.parsing_log)
  return _internal_parsing_log();
}
inline void MonitorInfo::unsafe_arena_set_allocated_parsing_log(
    ::monitor::proto::ParsingLog* parsing_log) {
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(parsing_log_);
  }
  parsing_log_ = parsing_log;
  if (parsing_log) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:monitor.proto.MonitorInfo.parsing_log)
}
inline ::monitor::proto::ParsingLog* MonitorInfo::release_parsing_log() {
  
  ::monitor::proto::ParsingLog* temp = parsing_log_;
  parsing_log_ = nullptr;
  if (GetArena() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
  return temp;
}
inline ::monitor::proto::ParsingLog* MonitorInfo::unsafe_arena_release_parsing_log() {
  // @@protoc_insertion_point(field_release:monitor.proto.MonitorInfo.parsing_log)
  
  ::monitor::proto::ParsingLog* temp = parsing_log_;
  parsing_log_ = nullptr;
  return temp;
}
inline ::monitor::proto::ParsingLog* MonitorInfo::_internal_mutable_parsing_log() {
  
  if (parsing_log_ == nullptr) {
    auto* p = CreateMaybeMessage<::monitor::proto::ParsingLog>(GetArena());
    parsing_log_ = p;
  }
  return parsing_log_;
}
inline ::monitor::proto::ParsingLog* MonitorInfo::mutable_parsing_log() {
  // @@protoc_insertion_point(field_mutable:monitor.proto.MonitorInfo.parsing_log)
  return _internal_mutable_parsing_log();
}
inline void MonitorInfo::set_allocated_parsing_log(::monitor::proto::ParsingLog* parsing_log) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArena();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(parsing_log_);
  }
  if (parsing_log) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
      reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(parsing_log)->GetArena();
    if (message_arena != submessage_arena) {
      parsing_log = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, parsing_log, submessage_arena);
    }
    
  } else {
    
  }
  parsing_log_ = parsing_log;
  // @@protoc_insertion_point(field_set_allocated:monitor.proto.MonitorInfo.parsing_log)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace proto
}  // namespace monitor

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_monitor_5finfo_2eproto

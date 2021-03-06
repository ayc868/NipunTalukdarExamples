/**
 * Autogenerated by Thrift Compiler (0.8.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef RemoteCommandService_H
#define RemoteCommandService_H

#include <TProcessor.h>
#include "remotecommand_types.h"

namespace RemoteCommand {

class RemoteCommandServiceIf {
 public:
  virtual ~RemoteCommandServiceIf() {}
  virtual int32_t executeCommand(const Command& cmd) = 0;
};

class RemoteCommandServiceIfFactory {
 public:
  typedef RemoteCommandServiceIf Handler;

  virtual ~RemoteCommandServiceIfFactory() {}

  virtual RemoteCommandServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(RemoteCommandServiceIf* /* handler */) = 0;
};

class RemoteCommandServiceIfSingletonFactory : virtual public RemoteCommandServiceIfFactory {
 public:
  RemoteCommandServiceIfSingletonFactory(const boost::shared_ptr<RemoteCommandServiceIf>& iface) : iface_(iface) {}
  virtual ~RemoteCommandServiceIfSingletonFactory() {}

  virtual RemoteCommandServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(RemoteCommandServiceIf* /* handler */) {}

 protected:
  boost::shared_ptr<RemoteCommandServiceIf> iface_;
};

class RemoteCommandServiceNull : virtual public RemoteCommandServiceIf {
 public:
  virtual ~RemoteCommandServiceNull() {}
  int32_t executeCommand(const Command& /* cmd */) {
    int32_t _return = 0;
    return _return;
  }
};

typedef struct _RemoteCommandService_executeCommand_args__isset {
  _RemoteCommandService_executeCommand_args__isset() : cmd(false) {}
  bool cmd;
} _RemoteCommandService_executeCommand_args__isset;

class RemoteCommandService_executeCommand_args {
 public:

  RemoteCommandService_executeCommand_args() {
  }

  virtual ~RemoteCommandService_executeCommand_args() throw() {}

  Command cmd;

  _RemoteCommandService_executeCommand_args__isset __isset;

  void __set_cmd(const Command& val) {
    cmd = val;
  }

  bool operator == (const RemoteCommandService_executeCommand_args & rhs) const
  {
    if (!(cmd == rhs.cmd))
      return false;
    return true;
  }
  bool operator != (const RemoteCommandService_executeCommand_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RemoteCommandService_executeCommand_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class RemoteCommandService_executeCommand_pargs {
 public:


  virtual ~RemoteCommandService_executeCommand_pargs() throw() {}

  const Command* cmd;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _RemoteCommandService_executeCommand_result__isset {
  _RemoteCommandService_executeCommand_result__isset() : success(false), badop(false) {}
  bool success;
  bool badop;
} _RemoteCommandService_executeCommand_result__isset;

class RemoteCommandService_executeCommand_result {
 public:

  RemoteCommandService_executeCommand_result() : success(0) {
  }

  virtual ~RemoteCommandService_executeCommand_result() throw() {}

  int32_t success;
  BadOperation badop;

  _RemoteCommandService_executeCommand_result__isset __isset;

  void __set_success(const int32_t val) {
    success = val;
  }

  void __set_badop(const BadOperation& val) {
    badop = val;
  }

  bool operator == (const RemoteCommandService_executeCommand_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(badop == rhs.badop))
      return false;
    return true;
  }
  bool operator != (const RemoteCommandService_executeCommand_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RemoteCommandService_executeCommand_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _RemoteCommandService_executeCommand_presult__isset {
  _RemoteCommandService_executeCommand_presult__isset() : success(false), badop(false) {}
  bool success;
  bool badop;
} _RemoteCommandService_executeCommand_presult__isset;

class RemoteCommandService_executeCommand_presult {
 public:


  virtual ~RemoteCommandService_executeCommand_presult() throw() {}

  int32_t* success;
  BadOperation badop;

  _RemoteCommandService_executeCommand_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class RemoteCommandServiceClient : virtual public RemoteCommandServiceIf {
 public:
  RemoteCommandServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  RemoteCommandServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    piprot_(iprot),
    poprot_(oprot) {
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  int32_t executeCommand(const Command& cmd);
  void send_executeCommand(const Command& cmd);
  int32_t recv_executeCommand();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class RemoteCommandServiceProcessor : public ::apache::thrift::TProcessor {
 protected:
  boost::shared_ptr<RemoteCommandServiceIf> iface_;
  virtual bool process_fn(apache::thrift::protocol::TProtocol* iprot, apache::thrift::protocol::TProtocol* oprot, std::string& fname, int32_t seqid, void* callContext);
 private:
  std::map<std::string, void (RemoteCommandServiceProcessor::*)(int32_t, apache::thrift::protocol::TProtocol*, apache::thrift::protocol::TProtocol*, void*)> processMap_;
  void process_executeCommand(int32_t seqid, apache::thrift::protocol::TProtocol* iprot, apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  RemoteCommandServiceProcessor(boost::shared_ptr<RemoteCommandServiceIf> iface) :
    iface_(iface) {
    processMap_["executeCommand"] = &RemoteCommandServiceProcessor::process_executeCommand;
  }

  virtual bool process(boost::shared_ptr<apache::thrift::protocol::TProtocol> piprot, boost::shared_ptr<apache::thrift::protocol::TProtocol> poprot, void* callContext);
  virtual ~RemoteCommandServiceProcessor() {}
};

class RemoteCommandServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  RemoteCommandServiceProcessorFactory(const ::boost::shared_ptr< RemoteCommandServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< RemoteCommandServiceIfFactory > handlerFactory_;
};

class RemoteCommandServiceMultiface : virtual public RemoteCommandServiceIf {
 public:
  RemoteCommandServiceMultiface(std::vector<boost::shared_ptr<RemoteCommandServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~RemoteCommandServiceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<RemoteCommandServiceIf> > ifaces_;
  RemoteCommandServiceMultiface() {}
  void add(boost::shared_ptr<RemoteCommandServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  int32_t executeCommand(const Command& cmd) {
    size_t sz = ifaces_.size();
    for (size_t i = 0; i < sz; ++i) {
      if (i == sz - 1) {
        return ifaces_[i]->executeCommand(cmd);
      } else {
        ifaces_[i]->executeCommand(cmd);
      }
    }
  }

};

} // namespace

#endif

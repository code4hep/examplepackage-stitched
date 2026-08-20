// From Stitched
#include "FWCore/Framework/interface/global/EDProducer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "FWCore/ParameterSet/interface/ConfigurationDescriptions.h"
#include "FWCore/Utilities/interface/EDPutToken.h"

// From examplepackage
#include "Example/DataFormats/ExampleProduct.h"

namespace examplepackage {
  class ExampleProducer : public edm::global::EDProducer<> {
  public:
    ExampleProducer(edm::ParameterSet const&) : putToken_(produces()) {}

    void produce(edm::StreamID, edm::Event& iEvent, edm::EventSetup const&) const final {
      iEvent.emplace(putToken_, 42);
    }

    static void fillDescriptions(edm::ConfigurationDescriptions& iDesc) {
      edm::ParameterSetDescription pset;
      iDesc.addDefault(pset);
    }

  private:
    edm::EDPutTokenT<ExampleProduct> putToken_;
  };
}

#include "FWCore/Framework/interface/MakerMacros.h"
DEFINE_FWK_MODULE(examplepackage::ExampleProducer);


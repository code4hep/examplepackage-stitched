// From Stitched
#include "FWCore/Framework/interface/global/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "FWCore/ParameterSet/interface/ConfigurationDescriptions.h"
#include "FWCore/Utilities/interface/EDGetToken.h"

// From examplepackage
#include "Example/DataFormats/ExampleProduct.h"

namespace examplepackage {
  class ExampleAnalyzer : public edm::global::EDAnalyzer<> {
  public:
    ExampleAnalyzer(edm::ParameterSet const& iConfig) :
      getToken_(consumes(iConfig.getUntrackedParameter<edm::InputTag>("source"))) {}

    void analyze(edm::StreamID, edm::Event const& iEvent, edm::EventSetup const&) const final {
      edm::LogPrint("ExampleAnalyzer") << "Analyze " << iEvent.get(getToken_).value();
    }

    static void fillDescriptions(edm::ConfigurationDescriptions& iDesc) {
      edm::ParameterSetDescription pset;
      pset.addUntracked<edm::InputTag>("source");
      iDesc.addDefault(pset);
    }

  private:
    edm::EDGetTokenT<ExampleProduct> getToken_;
  };
}

#include "FWCore/Framework/interface/MakerMacros.h"
DEFINE_FWK_MODULE(examplepackage::ExampleAnalyzer);

from FWCore.ParameterSet.Config import Process, EDAnalyzer, EDProducer, Task, EndPath, untracked
#from stitched import Process, EDAnalyzer, EDProducer, Task, EndPath, untracked

process = Process("TEST")

from FWCore.Modules.modules import EmptySource

process.source = EmptySource()

process.maxEvents.input = 3

from Example.Modules.modules import examplepackage_ExampleProducer, examplepackage_ExampleAnalyzer
process.testProducer = examplepackage_ExampleProducer()
process.testAnalyzer = examplepackage_ExampleAnalyzer(source = "testProducer")

# Without adjusting PYTHONPATH (or sourcing the env setups)
#process.testProducer = EDProducer("examplepackage::ExampleProducer")
#process.testAnalyzer = EDAnalyzer("examplepackage::ExampleAnalyzer",
#    source = untracked.InputTag("testProducer")
#)

process.p = EndPath(process.testAnalyzer, Task(process.testProducer))

#include "GenerateGameSink.h"
#include "EditorViewModel.h"
void GenerateGameSink::onGenerate(const std::vector<int>& fileGeneList, std::string filename) {
	m_eVM->generateFloorSet(fileGeneList, filename);
}
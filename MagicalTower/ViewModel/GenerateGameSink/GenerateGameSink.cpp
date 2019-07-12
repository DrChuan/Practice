#include "EditorViewModel.h"

bool GenerateGameSink::onGenerate(const std::vector<int>& fileGeneList, std::string filename) {
	return m_eVM->generateFloorSet(fileGeneList, filename);
}
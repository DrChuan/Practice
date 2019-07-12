#include "EditorViewModel.h"

bool GenerateGameSink::onGenerate(const std::vector<int>& fileGeneList, std::string filename) {
	if (filename.find('\\') == filename.npos)
		return m_eVM->generateFloorSet(fileGeneList, filename);
	else return false;
}
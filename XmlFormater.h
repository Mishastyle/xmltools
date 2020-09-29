#pragma once

#include <sstream>
#include <vector>
#include "XmlParser.h"

struct PrettyPrintParamsType {
	std::string indentChars;
	std::string eolChars;
	size_t maxIndentLevel;
	bool trimWhitespaceAroundText;
	bool autoCloseTags;
	bool indentAttributes;
	bool indentOnly;
};

enum class TrimModeType {
	NONE,
	LEFT,
	RIGHT,
	BOTH
};

class XmlFormater {
	XmlParser* parser = NULL;

	PrettyPrintParamsType prettyPrintParams;

	std::stringstream out;
	size_t indentLevel;

	void writeEOL();
	void writeIndentation();
	void updateIndentLevel(int change);
public:
	/*
	* Constructor
	* @param data The source data
	* @param length The source data length
	*/
	XmlFormater(const char* data, size_t length);

	/*
	* Constructor
	* @param data The source data
	* @param length The source data length
	* @param params The formater params
	*/
	XmlFormater(const char* data, size_t length, PrettyPrintParamsType params);

	/*
	/ Destructor
	*/
	~XmlFormater();

	void reset();

	/*
	* Generates a string containing a list of recognized tokens
	* This method has no other goal that help for debug
	* @return A string-reprensentation of all data tokens
	*/
	std::string debugTokens();

	/*
	* Performs pretty print formating
	* @return A reference string stream containing the formated string
	*/
	std::stringstream* prettyPrint();
};


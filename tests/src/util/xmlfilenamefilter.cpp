/*
 * Copyright 2004 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "xmlfilenamefilter.h"

using namespace log4cxx;
using namespace log4cxx::helpers;

XMLFilenameFilter::XMLFilenameFilter(const LogString& actual, const LogString& expected)
    : pattern(LOG4CXX_STR(" file=\"")),
      replacement(LOG4CXX_STR(" file=\"")) {
	LogString filename(actual);
	size_t backslash = filename.rfind(LOG4CXX_STR('\\'), filename.length() - 1);
	while (backslash != std::string::npos) {
		filename.replace(backslash, 1, LOG4CXX_STR("\\\\"), 2);
		if (backslash == 0) {
			backslash = std::string::npos;
		} else {
		    backslash = filename.rfind(LOG4CXX_STR('\\'), backslash - 1);
		}
	}
    pattern += filename;
    pattern += LOG4CXX_STR("\"");

    replacement += expected;
    replacement += LOG4CXX_STR("\"");
}

LogString XMLFilenameFilter::filter(const LogString& in)
	const throw(UnexpectedFormatException)
{
	return merge(pattern, in, replacement);
}


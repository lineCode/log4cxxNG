/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <log4cxxNG/net/sockethubappender.h>
#include "../appenderskeletontestcase.h"
#include <log4cxxNG/helpers/thread.h>
#include <apr.h>

using namespace log4cxx;
using namespace log4cxx::net;
using namespace log4cxx::helpers;

#if APR_HAS_THREADS
/**
   Unit tests of log4cxx::SocketHubAppender
 */
class SocketHubAppenderTestCase : public AppenderSkeletonTestCase
{
		LOGUNIT_TEST_SUITE(SocketHubAppenderTestCase);
		//
		//    tests inherited from AppenderSkeletonTestCase
		//
		LOGUNIT_TEST(testDefaultThreshold);
		LOGUNIT_TEST(testSetOptionThreshold);
		LOGUNIT_TEST(testActivateClose);
		LOGUNIT_TEST(testActivateSleepClose);
		LOGUNIT_TEST(testActivateWriteClose);
		LOGUNIT_TEST_SUITE_END();


	public:

		AppenderSkeleton* createAppenderSkeleton() const
		{
			return new log4cxx::net::SocketHubAppender();
		}

		void testActivateClose()
		{
			SocketHubAppenderPtr hubAppender(new SocketHubAppender());
			Pool p;
			hubAppender->activateOptions(p);
			hubAppender->close();
		}

		void testActivateSleepClose()
		{
			SocketHubAppenderPtr hubAppender(new SocketHubAppender());
			Pool p;
			hubAppender->activateOptions(p);
			Thread::sleep(1000);
			hubAppender->close();
		}


		void testActivateWriteClose()
		{
			SocketHubAppenderPtr hubAppender(new SocketHubAppender());
			Pool p;
			hubAppender->activateOptions(p);
			LoggerPtr root(Logger::getRootLogger());
			root->addAppender(hubAppender);

			for (int i = 0; i < 50; i++)
			{
				LOG4CXX_INFO(root, "Hello, World " << i);
			}

			hubAppender->close();
		}
};

LOGUNIT_TEST_SUITE_REGISTRATION(SocketHubAppenderTestCase);
#endif

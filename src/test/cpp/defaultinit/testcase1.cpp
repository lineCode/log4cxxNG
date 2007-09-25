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

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include <log4cxx/logmanager.h>
#include <log4cxx/logger.h>

using namespace log4cxx;

class TestCase1 : public CppUnit::TestFixture
{
   CPPUNIT_TEST_SUITE(TestCase1);
      CPPUNIT_TEST(noneTest);
   CPPUNIT_TEST_SUITE_END();
   
public:
   void setUp()
   {
   }

   void tearDown()
   {
      LogManager::shutdown();
   }
   
   void noneTest()
   {
      LoggerPtr root = Logger::getRootLogger();
     LOG4CXX_DEBUG(root, "Hello, world");
      bool rootIsConfigured = !root->getAllAppenders().empty();
      CPPUNIT_ASSERT(!rootIsConfigured);
   }
};

CPPUNIT_NS::Test* createTestCase1() {
   return TestCase1::suite();
}

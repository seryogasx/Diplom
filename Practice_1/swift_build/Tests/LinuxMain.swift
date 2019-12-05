import XCTest

import swift_buildTests

var tests = [XCTestCaseEntry]()
tests += swift_buildTests.allTests()
XCTMain(tests)

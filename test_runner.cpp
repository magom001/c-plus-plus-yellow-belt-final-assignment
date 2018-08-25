//
// Created by a.magomedov on 21.08.2018.
//

#include "test_runner.h"

TestRunner::~TestRunner() {
    if (fail_count > 0) {
        cerr << fail_count << " unit tests failed. Terminate" << endl;
        exit(1);
    }
}

void Assert(bool b, const string &hint)  {
    AssertEqual(b, true, hint);
}
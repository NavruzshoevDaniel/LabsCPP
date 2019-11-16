#include "../Commands/ReadFile.h"
#include "../Commands/Replace.h"
#include "../Commands/Sort.h"
#include "../Commands/WriteFile.h"
#include "../Commands/Grep.h"
#include "../Commands/Dump.h"
#include "Creator.h"

static Creator<ReadFile> rfCreator("readfile");
static Creator<Sort> sCreator("sort");
static Creator<Replace> rpCreator("replace");
static Creator<WriteFile> wfCreator("writefile");
static Creator<Dump> dCreator("dump");
static Creator<Grep> gCreator("grep");

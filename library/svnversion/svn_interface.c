#include <stdlib.h>

#ifndef IGNORE_SVNVERSION
// Will use 'ya dump vcs-revision --cxx-out' output here
// #include "vcs.h"
#include <library/svnversion/svnversion_data.h>
#endif


#define FROM_IMPL
#include "svnversion.h"

#define STR1(x) #x
#define STR2(x) STR1(x)

const char* GetProgramSvnVersion() {
#if defined(REVISION)
// for package systems generating from svn export but providing REVISION macro
#define STRREVISION STR2(REVISION)
#define REVISIONINFO "r" STRREVISION
#if defined(PROGRAM_VERSION)
    return PROGRAM_VERSION "\n\n" REVISIONINFO;
#else
    return REVISIONINFO " "__DATE__
                        " "__TIME__;
#endif
#elif defined(PROGRAM_VERSION)
    return PROGRAM_VERSION;
#else
    return "No program version found";
#endif
}

const char* GetArcadiaSourcePath() {
#if defined(ARCADIA_SOURCE_PATH)
    return ARCADIA_SOURCE_PATH;
#else
    return "";
#endif
}

const char* GetArcadiaSourceUrl() {
#if defined(ARCADIA_SOURCE_URL)
    return ARCADIA_SOURCE_URL;
#else
    return "";
#endif
}

int GetArcadiaLastChangeNum() {
#if defined(ARCADIA_SOURCE_LAST_CHANGE)
    return atoi(ARCADIA_SOURCE_LAST_CHANGE);
#else
    return 0;
#endif
}

const char* GetArcadiaLastChange() {
#if defined(ARCADIA_SOURCE_LAST_CHANGE)
    return ARCADIA_SOURCE_LAST_CHANGE;
#else
    return "";
#endif
}

const char* GetArcadiaLastAuthor() {
#if defined(ARCADIA_SOURCE_LAST_AUTHOR)
    return ARCADIA_SOURCE_LAST_AUTHOR;
#else
    return "";
#endif
}

int GetProgramSvnRevision() {
#if defined(ARCADIA_SOURCE_REVISION)
    return atoi(ARCADIA_SOURCE_REVISION);
#else
    return 0;
#endif
}

const char* GetProgramHgHash() {
#if defined(ARCADIA_SOURCE_HG_HASH)
    return ARCADIA_SOURCE_HG_HASH;
#else
    return "";
#endif
}

const char* GetProgramScmData() {
#if defined(SCM_DATA)
    return SCM_DATA;
#else
    return "";
#endif
}

const char* GetProgramBuildUser() {
#if defined(BUILD_USER)
    return BUILD_USER;
#else
    return "";
#endif
}

const char* GetProgramBuildHost() {
#if defined(BUILD_HOST)
    return BUILD_HOST;
#else
    return "";
#endif
}

const char* GetProgramBuildDate() {
#if defined(BUILD_DATE)
    return BUILD_DATE;
#else
    return "";
#endif
}

const char* GetVCS() {
#if defined(VCS)
    return VCS;
#else
    return "";
#endif
}

const char* GetBranch() {
#if defined(BRANCH)
    return BRANCH;
#else
    return "";
#endif
}
#undef FROM_IMPL

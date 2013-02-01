// 이 MFC 샘플 소스 코드는 MFC Microsoft Office Fluent 사용자 인터페이스("Fluent UI")를 
// 사용하는 방법을 보여 주며, MFC C++ 라이브러리 소프트웨어에 포함된 
// Microsoft Foundation Classes Reference 및 관련 전자 문서에 대해 
// 추가적으로 제공되는 내용입니다.  
// Fluent UI를 복사, 사용 또는 배포하는 데 대한 사용 약관은 별도로 제공됩니다.  
// Fluent UI 라이선싱 프로그램에 대한 자세한 내용은 
// http://msdn.microsoft.com/officeui를 참조하십시오.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

#pragma once

// 다음 매크로는 필요한 최소 플랫폼을 정의합니다. 필요한 최소 플랫폼은
// 응용 프로그램을 실행하는 데 필요한 기능이 포함된 가장 빠른 버전의 Windows, Internet Explorer
// 등입니다. 이 매크로는 지정된 버전 이상의 플랫폼 버전에서 사용 가능한 모든 기능을 활성화해야
// 작동합니다.

// 아래 지정된 플랫폼에 우선하는 플랫폼을 대상으로 하는 경우 다음 정의를 수정하십시오.
// 다른 플랫폼에 사용되는 해당 값의 최신 정보는 MSDN을 참조하십시오.
#ifndef WINVER                          // 필요한 최소 플랫폼을 Windows Vista로 지정합니다.
#define WINVER 0x0600           // 다른 버전의 Windows에 맞도록 적합한 값으로 변경해 주십시오.
#endif

#ifndef _WIN32_WINNT            // 필요한 최소 플랫폼을 Windows Vista로 지정합니다.
#define _WIN32_WINNT 0x0600     // 다른 버전의 Windows에 맞도록 적합한 값으로 변경해 주십시오.
#endif

#ifndef _WIN32_WINDOWS          // 필요한 최소 플랫폼을 Windows 98로 지정합니다.
#define _WIN32_WINDOWS 0x0410 // Windows Me 이상에 맞도록 적합한 값으로 변경해 주십시오.
#endif

#ifndef _WIN32_IE                       // 필요한 최소 플랫폼을 Internet Explorer 7.0으로 지정합니다.
#define _WIN32_IE 0x0700        // 다른 버전의 IE에 맞도록 적합한 값으로 변경해 주십시오.
#endif


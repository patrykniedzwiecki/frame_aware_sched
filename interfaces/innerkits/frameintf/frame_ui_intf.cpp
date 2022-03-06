/*
 * Copyright (c) 2022 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "frame_ui_intf.h"

#include "frame_info_const.h"
#include "rme_constants.h"
#include "frame_msg_mgr.h"

namespace OHOS {
namespace RME {
DEFINE_RMELOG_INTELLISENSE("ueaCleint-FrameUiIntf");

FrameUiIntf& FrameUiIntf::GetInstance()
{
    static FrameUiIntf instance;
    return instance;
}

void FrameUiIntf::Init()
{
    if (inited) {
        return;
    }
    int ret = FrameMsgMgr::GetInstance().Init();
    if (!ret) {
        inited = false;
    } else {
        inited = true;
    }
    RME_LOGI("[Init]:ret:%{public}d, inited:%{public}d", ret, inited);
}

int FrameUiIntf::GetSenseSchedEnable()
{
    if (!inited) {
        return static_cast<int>(ErrorCode::FAIL);
    }
    return static_cast<int>(ErrorCode::SUCC);
}

void FrameUiIntf::BeginFlushAnimation() const
{
    RME_LOGI("[BeginFlushAnimation]:start");
    if (!inited) {
        return;
    }
    FrameMsgMgr::GetInstance().EventUpdate(FrameEvent::FLUSH_ANIMATION, EventState::EVENT_ENTER);
}

void FrameUiIntf::EndFlushAnimation() const
{
    if (!inited) {
        return;
    }
    FrameMsgMgr::GetInstance().EventUpdate(FrameEvent::FLUSH_BUILD, EventState::EVENT_EXIT);
}

void FrameUiIntf::BeginFlushBuild() const
{
    if (!inited) {
        return;
    }
    FrameMsgMgr::GetInstance().EventUpdate(FrameEvent::FLUSH_BUILD, EventState::EVENT_ENTER);
}

void FrameUiIntf::EndFlushBuild() const
{
    if (!inited) {
        return;
    }
    FrameMsgMgr::GetInstance().EventUpdate(FrameEvent::FLUSH_BUILD, EventState::EVENT_EXIT);
}

void FrameUiIntf::BeginFlushLayout() const
{
    if (!inited) {
        return;
    }
    FrameMsgMgr::GetInstance().EventUpdate(FrameEvent::FLUSH_LAYOUT, EventState::EVENT_ENTER);
}

void FrameUiIntf::EndFlushLayout() const
{
    if (!inited) {
        return;
    }
    FrameMsgMgr::GetInstance().EventUpdate(FrameEvent::FLUSH_LAYOUT, EventState::EVENT_EXIT);
}

void FrameUiIntf::BeginFlushRender() const
{
    if (!inited) {
        return;
    }
    FrameMsgMgr::GetInstance().EventUpdate(FrameEvent::FLUSH_RENDER, EventState::EVENT_ENTER);
}

void FrameUiIntf::EndFlushRender() const
{
    if (!inited) {
        return;
    }
    FrameMsgMgr::GetInstance().EventUpdate(FrameEvent::FLUSH_RENDER, EventState::EVENT_EXIT);
}

void FrameUiIntf::BeginFlushRenderFinish() const
{
    if (!inited) {
        return;
    }
    FrameMsgMgr::GetInstance().EventUpdate(FrameEvent::FLUSH_RENDER_FINISH, EventState::EVENT_ENTER);
}

void FrameUiIntf::EndFlushRenderFinish() const
{
    if (!inited) {
        return;
    }
    FrameMsgMgr::GetInstance().EventUpdate(FrameEvent::FLUSH_RENDER_FINISH, EventState::EVENT_EXIT);
}

void FrameUiIntf::BeginProcessPostFlush() const
{
    if (!inited) {
        return;
    }
    FrameMsgMgr::GetInstance().EventUpdate(FrameEvent::PROCESS_POST_FLUSH, EventState::EVENT_ENTER);
}

void FrameUiIntf::ProcessCommandsStart() const
{
    if (!inited) {
        return;
    }
    FrameMsgMgr::GetInstance().EventUpdate(FrameEvent::PROCESS_COMMANDS, EventState::EVENT_ENTER);
}

void FrameUiIntf::AnimateStart() const
{
    if (!inited) {
        return;
    }
    FrameMsgMgr::GetInstance().EventUpdate(FrameEvent::ANIMATE, EventState::EVENT_ENTER);
}

void FrameUiIntf::RenderStart() const
{
    if (!inited) {
        return;
    }
    FrameMsgMgr::GetInstance().EventUpdate(FrameEvent::RENDER, EventState::EVENT_ENTER);
}

void FrameUiIntf::SendCommandsStart() const
{
    if (!inited) {
        return;
    }
    FrameMsgMgr::GetInstance().EventUpdate(FrameEvent::SEND_COMMANDS, EventState::EVENT_ENTER);
}

void FrameUiIntf::BeginListFling() const
{
    if (!inited) {
        return;
    }
    FrameMsgMgr::GetInstance().EventUpdate(FrameEvent::EVENT_BEGIN_FRAME, EventState::EVENT_ENTER);
}

void FrameUiIntf::EndListFling() const
{
    if (!inited) {
        return;
    }
    FrameMsgMgr::GetInstance().EventUpdate(FrameEvent::EVENT_END_FRAME, EventState::EVENT_ENTER);
}

extern "C" void Init()
{
    FrameUiIntf::GetInstance().Init();
}

extern "C" int GetSenseSchedEnable()
{
    return FrameUiIntf::GetInstance().GetSenseSchedEnable();
}

extern "C" void BeginFlushAnimation()
{
    FrameUiIntf::GetInstance().BeginFlushAnimation();
}

extern "C" void EndFlushAnimation()
{
    FrameUiIntf::GetInstance().EndFlushAnimation();
}

extern "C" void BeginFlushBuild()
{
    FrameUiIntf::GetInstance().BeginFlushBuild();
}

extern "C" void EndFlushBuild()
{
    FrameUiIntf::GetInstance().EndFlushBuild();
}

extern "C" void BeginFlushLayout()
{
    FrameUiIntf::GetInstance().BeginFlushLayout();
}

extern "C" void EndFlushLayout()
{
    FrameUiIntf::GetInstance().EndFlushLayout();
}

extern "C" void BeginFlushRender()
{
    FrameUiIntf::GetInstance().BeginFlushRender();
}

extern "C" void EndFlushRender()
{
    FrameUiIntf::GetInstance().EndFlushRender();
}

extern "C" void BeginFlushRenderFinish()
{
    FrameUiIntf::GetInstance().BeginFlushRenderFinish();
}

extern "C" void EndFlushRenderFinish()
{
    FrameUiIntf::GetInstance().EndFlushRenderFinish();
}

extern "C" void BeginProcessPostFlush()
{
    FrameUiIntf::GetInstance().BeginProcessPostFlush();
}

extern "C" void ProcessCommandsStart()
{
    FrameUiIntf::GetInstance().ProcessCommandsStart();
}

extern "C" void AnimateStart()
{
    FrameUiIntf::GetInstance().AnimateStart();
}

extern "C" void RenderStart()
{
    FrameUiIntf::GetInstance().RenderStart();
}

extern "C" void SendCommandsStart()
{
    FrameUiIntf::GetInstance().SendCommandsStart();
}

extern "C" void BeginListFling()
{
    FrameUiIntf::GetInstance().BeginListFling();
}

extern "C" void EndListFling()
{
    FrameUiIntf::GetInstance().EndListFling();
}
} // namespace RME
} // namespace OHOS

﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using Dust.Core;

namespace Dust.Gui
{
    public interface IGuiText : IGuiComponent
    {
        String getText();
        DustData getActivationData();
    }
}

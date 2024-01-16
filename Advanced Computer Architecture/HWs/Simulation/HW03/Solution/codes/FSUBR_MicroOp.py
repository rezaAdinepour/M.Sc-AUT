def macroop FSUBR1_R
{
    subfp st(0), sti, st(0)
};


def macroop FSUBR1_M
{
    ldfp ufp1, seg, sib, disp
    subfp st(0), ufp1, st(0)
};

def macroop FSUBR1_P
{
    rdip t7
    ldfp ufp1, seg, riprel, disp
    subfp st(0), ufp1, st(0)
};

def macroop FSUBR2_R
{
    subfp sti, st(0), sti
};

def macroop FSUBR2_M
{
    ldfp ufp1, seg, sib, disp
    subfp st(0), ufp1, st(0)
};

def macroop FSUBR2_P
{
    rdip t7
    ldfp ufp1, seg, riprel, disp
    subfp st(0), ufp1, st(0)
};

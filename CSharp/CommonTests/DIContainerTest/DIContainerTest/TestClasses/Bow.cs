using DIContainerTest.Resources;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DIContainerTest.TestClasses
{
    public class Bow : IWeapon
    {
        public string GetWeaponName()
        {
            return Texts.Bow;
        }
    }
}

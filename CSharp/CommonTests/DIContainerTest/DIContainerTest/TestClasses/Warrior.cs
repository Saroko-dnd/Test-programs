using DIContainerTest.Resources;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DIContainerTest.TestClasses
{
    public class Warrior
    {
        private IWeapon CurrentWeapon;

        public Warrior(IWeapon TempWeapon)
        {
            CurrentWeapon = TempWeapon;
        }

        public string GetGearAsString()
        {
            return Texts.Gear + " " + CurrentWeapon.GetWeaponName();
        }
    }
}

using DIContainerTest.Resources;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DIContainerTest.TestClasses
{
    public class WarriorWithConstructor
    {
        private string WarriorName;

        private IWeapon CurrentWeapon;

        public string GetGearAsString()
        {
            return WarriorName + " " + Texts.Has + " " + CurrentWeapon.GetWeaponName();
        }

        public WarriorWithConstructor(IWeapon NewWeapon, string NewName)
        {
            CurrentWeapon = NewWeapon;
            WarriorName = NewName;
        }
    }
}

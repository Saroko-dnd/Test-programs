using DIContainerTest.Resources;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DIContainerTest.TestClasses
{
    public class Sword : IWeapon
    {
        private string SwordMaterial;

        public string GetWeaponName()
        {
            return SwordMaterial + " " + Texts.Sword;
        }

        public Sword(string NewSwordMaterial)
        {
            SwordMaterial = NewSwordMaterial;
        }
    }
}

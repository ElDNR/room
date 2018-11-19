using System;
using System.Collections.Generic;

namespace room.server.data.Models
{
    public partial class Color
    {
        public Color()
        {
            Rendering = new HashSet<Rendering>();
        }

        public int Id { get; set; }
        public double Red { get; set; }
        public double Green { get; set; }
        public double Blue { get; set; }
        public double Alpha { get; set; }
        public string Description { get; set; }

        public ICollection<Rendering> Rendering { get; set; }
    }
}

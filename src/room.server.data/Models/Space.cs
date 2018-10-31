using System;
using System.Collections.Generic;

namespace room.server.data.Models
{
    public partial class Space
    {
        public Space()
        {
            Rendering = new HashSet<Rendering>();
        }

        public int Id { get; set; }
        public double X { get; set; }
        public double Y { get; set; }
        public double Z { get; set; }
        public string Description { get; set; }

        public ICollection<Rendering> Rendering { get; set; }
    }
}

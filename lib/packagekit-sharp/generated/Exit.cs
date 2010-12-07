// This file was generated by the Gtk# code generator.
// Any changes made will be lost if regenerated.

namespace PackageKit {

	using System;
	using System.Runtime.InteropServices;

#region Autogenerated code
	public class Exit {

		[DllImport("libpackagekit-glib.dll")]
		static extern IntPtr pk_exit_enum_to_string(int exit);

		public static string EnumToText(PackageKit.ExitEnum exit) {
			IntPtr raw_ret = pk_exit_enum_to_string((int) exit);
			string ret = GLib.Marshaller.Utf8PtrToString (raw_ret);
			return ret;
		}

		[DllImport("libpackagekit-glib.dll")]
		static extern int pk_exit_enum_from_string(IntPtr exit);

		public static PackageKit.ExitEnum EnumFromText(string exit) {
			IntPtr native_exit = GLib.Marshaller.StringToPtrGStrdup (exit);
			int raw_ret = pk_exit_enum_from_string(native_exit);
			PackageKit.ExitEnum ret = (PackageKit.ExitEnum) raw_ret;
			GLib.Marshaller.Free (native_exit);
			return ret;
		}

#endregion
	}
}

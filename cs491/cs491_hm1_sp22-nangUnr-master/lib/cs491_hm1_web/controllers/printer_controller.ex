defmodule Cs491Hm1Web.PrinterController do
  use Cs491Hm1Web, :controller

  alias Cs491Hm1.OfficeAssets
  alias Cs491Hm1.OfficeAssets.Printer

  def index(conn, _params) do
    printer = OfficeAssets.list_printer()
    render(conn, "index.html", printer: printer)
  end

  def new(conn, _params) do
    changeset = OfficeAssets.change_printer(%Printer{})
    render(conn, "new.html", changeset: changeset)
  end

  def create(conn, %{"printer" => printer_params}) do
    case OfficeAssets.create_printer(printer_params) do
      {:ok, printer} ->
        conn
        |> put_flash(:info, "Printer created successfully.")
        |> redirect(to: Routes.printer_path(conn, :show, printer))

      {:error, %Ecto.Changeset{} = changeset} ->
        render(conn, "new.html", changeset: changeset)
    end
  end

  def show(conn, %{"id" => id}) do
    printer = OfficeAssets.get_printer!(id)
    render(conn, "show.html", printer: printer)
  end

  def edit(conn, %{"id" => id}) do
    printer = OfficeAssets.get_printer!(id)
    changeset = OfficeAssets.change_printer(printer)
    render(conn, "edit.html", printer: printer, changeset: changeset)
  end

  def update(conn, %{"id" => id, "printer" => printer_params}) do
    printer = OfficeAssets.get_printer!(id)

    case OfficeAssets.update_printer(printer, printer_params) do
      {:ok, printer} ->
        conn
        |> put_flash(:info, "Printer updated successfully.")
        |> redirect(to: Routes.printer_path(conn, :show, printer))

      {:error, %Ecto.Changeset{} = changeset} ->
        render(conn, "edit.html", printer: printer, changeset: changeset)
    end
  end

  def delete(conn, %{"id" => id}) do
    printer = OfficeAssets.get_printer!(id)
    {:ok, _printer} = OfficeAssets.delete_printer(printer)

    conn
    |> put_flash(:info, "Printer deleted successfully.")
    |> redirect(to: Routes.printer_path(conn, :index))
  end
end
